xselect
=======

`xselect` is very simple. It waits for activity on stdin, and then executes
`argv[1]` with arguments `argv[1..n]`.

A contrived example:

    $ (sleep 5 && echo hi) | ls -l          # ls executes immediately
    $ (sleep 5 && echo hi) | xselect ls -l  # ls executes after 5 seconds


**Install**

    $ make
    $ sudo make install
