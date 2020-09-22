#!/bin/bash
#exec 2> /dev/null


pw="arrowhead"
user="arrowhead"
table="arrowhead"

app=false;

function helpF () {
	echo "Read a .json and add the this_system, target_system, service and authorization_intra_cloud to the arrowhead database."
	echo "Usage: ah_gen_db_setup [OPTIONS]... -f [.json file]"
	echo "Flags:"
	echo "-a	only set this_system"
	echo "-d	set database user"
	echo "-f	set json file, required"
	echo "-h	display these messages"
	echo "-p	password to database"
	echo "-u	set the database to be used"
	echo ""
	echo "The data base warns for the password usages, ignore those. If security is a concern do not use these script"
	echo "requires jq: apt install jq"
	exit 0
}

while getopts p:u:d:hf:a aflag; do
	case $aflag in
		a) app=true;;
		p) pw=$OPTARG;;
		u) user=$OPTARG;;
		d) table=$OPTARG;;
		h) helpF;;
		f) file="/home/albin/Documents/client-cpp/example""/""$OPTARG";;
	esac
done




thisName=$(jq '.this_system.this_name' "$file")
temp=$?
if [ "$temp" != 0 ]; then
	echo "file not a correct json"
	exit
fi
thisAddress=$(jq '.this_system.this_address' "$file")
thisPort=$(jq '.this_system.this_port' "$file")

targetName=$(jq '.target_system.target_name' "$file")
if [ "$targetName" == null ]; then
	echo "no target in json"
	exit
fi
targetAddress=$(jq '.target_system.target_address' "$file")
targetPort=$(jq '.target_system.target_port' "$file")

serviceName=$(jq '.service.service_name' "$file")

returnVal=0

# $1 = table name
# $2 = id
function findID () {
	test1="notEmty"
	temp="$2" 
	while [ "$test1" != "" ]
	do
		let "temp++"
		test1=$(mysql -u "$user" -p"$pw" -D "$table" -N -e "select * from ""$1"" where id = ""$temp"";")
	done
	returnVal=$temp
}

# $1 = system name
# $2 = address
# $3 = port
function fixSystem() {
	local id=""
	id=$(mysql -u "$user" -p"$pw" -D "$table" -e "select id from system_ where system_name = ""$1"";" -N)
	if [ "${id}" == "" ]; then
		findID system_ "$id"
		id=$returnVal
		mysql -u "$user" -p"$pw" -D "$table" -e "insert into system_ (id, system_name, address, port, authentication_info)  values(""$id"", ""$1"",  ""$2"" , ""$3"", '');"
	fi
	returnVal=$id
}

fixSystem "$thisName" "$thisAddress" "$thisPort" 
IDthis="$returnVal"
echo "This system is in."

if [ "$app" == true ]; then
	exit 0
fi

fixSystem "$targetName" "$targetAddress" "$targetPort"
IDtarget="$returnVal"
echo "Target system is in."

# service
IDservice=$(mysql -u "$user" -p"$pw" -D "$table" -e "select id from service_definition where service_definition = ""$serviceName"";" -N)

if [ "$IDservice" == "" ]; then
	findID	service_definition "$IDservice"
	IDservice="$returnVal"
	mysql -u "$user" -p"$pw" -D "$table" -e "insert into service_definition (id, service_definition) values(""$IDservice"", ""$serviceName"");"
fi

echo "Service is in"

# intra
test1=$(mysql -u "$user" -p"$pw" -D "$table" -e "select * from authorization_intra_cloud where consumer_system_id=""$IDthis"" AND provider_system_id=""$IDtarget"" AND service_id=""$IDservice"";")

if [ "$test1" == "" ]; then
	findID authorization_intra_cloud 1
	index="$returnVal"
	mysql -u "$user" -p"$pw" -D "$table" -e "insert into authorization_intra_cloud (id, consumer_system_id, provider_system_id, service_id) values(""$index"",""$IDthis"",""$IDtarget"",""$IDservice"");"
fi

echo "Done!"


