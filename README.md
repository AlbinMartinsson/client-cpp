# Arrowhead framework client C++  
These is a library to enable the use of Arrowhead framework with `c++`
code.
It is designed to be installed ass a dynamic library.

## Prerequisites
The following Linux packages are prerequisites:

> sudo apt install openssl, libgnutls28-dev libgnutlsxx28 libssl1.1 libssl1.0-dev libcurl3 libcurl3-gnutls libcurl4-gnutls-dev libcrypto++-dev libcrypto++-utils libcrypto++6 libgpg-error-dev automake texinfo g++ libjson-c-dev jq

The project uses libmicrohttpd-0.9.59 as well. Download, compile and install it from source with HTTPS support: https://ftp.gnu.org/gnu/libmicrohttpd/

> tar -xvzf libmicrohttpd-0.9.59.tar.gz
> ./configure --with-gnutls  
> make  
> sudo make install  

Create libmicrohttpd.so.12 file in `/usr/lib` or `usr/local/lib` directory (or where your build path is pointing):

> cd /usr/lib  
> sudo ln –s /usr/local/lib/libmicrohttpd.so.12.46.0 libmicrohttpd.so.12  

In a case of missing libcrypto.so:
> cd /usr/lib  
> sudo ln –s libcrypto.so.1.0.0 /lib/arm-linux-gnueabihf/libcrypt-2.24.so  

## Installation
To install de library clone these project.
Navigate to the source folder and run:

> cmake CMakeLists.txt  
> sudo make install


## Usages
To use the library you need to include the library in your build path.
To do sow add the following to your `CMakeLists.txt`
```
set(PROJECT_LINK_LIBS libarrowhead_cpp.so)
link_directories(/usr/local/lib/)
target_link_libraries(${your_project_name} ${PROJECT_LINK_LIBS})
```
In the code do you include the type of Arrowhead system you desire:
provider, consumer, publisher or subscriber.
```cpp
#include "arrowhead/Provider.h"
#include "arrowhead/Consumer.h"
#include "arrowhead/Publisher.h"
#include "arrowhead/Subscriber.h"
```
They are written in `namespace arrowhead`.
You can off curse include ass many ass you need.
### Provider example
```cpp
Provider my_provider("path_to_json_with_settings");
my_provider.setMsgs(json_object);
```
or with your on callback for when requests are received. 
```cpp
int callbackFunktion(const char *URL, std::string *return_data);
Provider my_provider("path_to_json_with_settings", callbackFunktion);
```
or
```cpp
Provider my_provider;
my_provider.config /.../
my_provider.init();
my_provider.setMsgs(json_object)
```
`my_provider.config` is a struct containing settings, see more under
`config`.
The `json_object` shod contain the msgs you providing.
The callbackFunction need to be a int returner.
It returns 1 when it is working.
And the parameters need to be of type `const char*` and `std::string*`.

### Consumer example
```cpp
Consumer my_consumer(path_to_json_with_setting, callbackFunction);
my_consumer.request();
```
or
```cpp
Consumer my_consumer;
my_consumer.config /.../
my_consumer.init(callbackFunction);
my_consumer.request();
```
The callbackFunction have to bi a `void` whit parameter `const
char*` sending_url, `const char*` msgs.

### Publisher example
```cpp
Publisher my_publisher(path_to_json_with_settings);
my_publisher.publish(json_object);
```
or
```cpp
Publisher my_publisher;
my_publisher.config /.../
my_publisher.init();
my_publisher.publish(json_object);
```

### Subscriber example
```cpp
Subscriber my_subscriber(path_to_json_with_settings, callbackFuncton);
```
or
```cpp
Subscriber my_subscriber;
my_subscriber.config /.../
my_subscriber.init(callbackFunction);
```
The callbackFunction have to bi a `void` whit parameter `const
char*` sending_url, `const char*` msgs.

#### For examples see `example/`

### Config
Arrowhead framework require some system specific parameters to work.
Those parameters are set by the `config` struct.
The parameters need to be set before the `init` function.
It is recommended to create a launch file (.json) where these parameters are
define and then loaded in code.
Many of these parameters need to sync with the rest of the system and you
only wants to set the parameter once.
It is left to you to figure out how to do that best in your
system.

The parameters are: (all is not always used)


| Parameter name 				| Type 		| Usages |
|:------------------------------|:----------|:-------|
| ACCESS_URI					| string	| URI to serviseRegestry or orchestration |
| SECURE_ARROWHEAD_INTERFACE	| bool		| Is HTTPs used to interface with core|
| SECURE_PROVIDER_INTERFACE		| bool		| Is HTTPs used to interface with provider |
| PUBLIC_KEY_PATH				| string	| Absolute path to public key |
| PRIVATE_KEY_PATH				| string	| Absolute path to private key |
| OVERRIDE_STORE				| bool		| Orchestration flags |
| MATCHMAKING					| bool		| Orchestration flags |
| METADATA_SEARCH				| bool		| Orchestration flags |
| PING_PROVIDERS				| bool		| Orchestration flags |
| ONLY_PREFERRED				| bool		| Orchestration flags |
| EXTERNAL_SERVICE_REQUEST		| bool		| Orchestration flags |
| THIS_SYSTEM_NAME				| string	| This systems name |
| THIS_ADDRESS					| string 	| This system's address|
| THIS_PORT						| int		| This system's port |
| TARGET_SYSTEM_NAME			| string	| Target system's name |
| TARGET_ADDRESS				| string	| Target system's address|
| TARGET_PORT 					| int		| Target system's port |
| SERVICE_NAME					| string	| Name of the service |
| SERVICE_URI					| string	| Identification string |
| INTERFACE						| string	| Interface used ex. JSON |
| SECURITY						| string	| Type of security ex. Token |
| UNIT							| string	| The unit of the service data |


# Work to do
## HTTPs
At the moment is no HTTPs functionality implemented.
Some code for that do exist.
The existing HTTPs code need to be split (like with HttpsHandler and HttpHandler) from non HTTP code to create 
a good code structure.

## Code robustness
There are a some checks to inshore that the correct messages are sent.
These checks are not covering all cases.
It would be a good idea to extend these sow bad things don't happen.
