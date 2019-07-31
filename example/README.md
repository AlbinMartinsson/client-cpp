# Examples

There are 5 unique example.
One of each type of system: provider, consumer, publisher and subscriber.
And one alternative provider.
To the alternative provider a corresponding consumer with appropriate
`callback_consumer.json`.


To make them work do you need to change the `.json` files to match your
system.
You all sow need to add the consumer and publisher in the database, table
'arrowhead_system'.
And add the connections in 'intra_cloud_authorization'.
These can be don by:

> ah_gen_db_setup -f consumer.json  
> ah_gen_db_setup -f publisher.json  
> ah_gen_db_setup -f callback_consumer.json

For more information on usages run `ah_gen_db_setup -h`.

To build the examples run:

> cmake CMakeLists.txt  
> make  

To run the examples:

> bin/example_provider  
> bin/example_consumer  
> bin/example_publisher  
> bin/example_subscriber  
> bin/example_callback_provider  
> bin/example_callback_consumer

With `run_all.sh` can you run all examples.
It requires `tmux`, to install `tmux` `sudo atp install tmux`.
And run `./run_all.sh`.
It will open a `tmux` window with six panels, one for each example.
The layout is:

| layout | nodes |
|---|
| example_provider | example_consumer |
| example_publisher | example_subscriber |
| example_callback_provider | example_callback_consumer |

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
