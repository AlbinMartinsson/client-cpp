#!/bin/bash

tmux start-server
tmux new-session -d -s "ah"


tmux splitp -v -p 66
tmux splitp -v -p 50

tmux splitp -h

tmux selectp -t 0
tmux splitp -h

tmux selectp -t 2
tmux splitp -h

tmux send-key -t 0 "bin/example_provider" C-m
tmux send-key -t 3 "bin/example_subscriber" C-m
tmux send-key -t 4 "bin/example_callback_provider" C-m
sleep 1s
tmux send-key -t 1 "bin/example_consumer" C-m
tmux send-key -t 2 "bin/example_publisher" C-m
tmux send-key -t 5 "bin/example_callback_consumer" C-m

tmux attach
