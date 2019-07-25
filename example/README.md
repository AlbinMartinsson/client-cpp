# Examples

There are 4 example.
One of each type of system: provider, consumer, publisher and subscriber.

To make them work do you need to change the `.json` files to match your
system.
You all sow need to add the consumer and publisher in the database, table
'arrowhead_system'.
And add the connections in 'intra_cloud_authorization'.


To build the examples run:

> cmake CMakeLists.txt  
> make  

To run the examples:

> bin/example_provider  
> bin/example_consumer  
> bin/example_publisher  
> bin/example_subscriber  

There is all sow a test build.
To run that:

> bin/uTest 

## Information
The `test_example.json` are a example that describe how to create your one
`.json`.
The other `.json` are wot you need for the specific system.
To launch multiple types in one system is it easiest to have multiple
`.json`.
But keep in mind that names and numbers need to agree for it to work.
