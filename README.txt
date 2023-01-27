NAME
    my_radar

SYNOPSIS
    Air traffic simulation panel

DESCRIPTION
    ./my_radar [OPTIONS] path_to_script
    path_to_script : The path to the script file.

    OPTIONS
        -h
            display the help
        -R
            disable sprite rotation
        -L
            start the simulation with hitboxes and areas disabled
        -S
            start the simulation with sprites disabled
        -B
            start the simulation with background disable
        -G
            start the simulation with the grid enable
        -M <value>
            start the simulation with a given speed
                the speed as to be a positive integer between 1 and 4
                if the value is bad, the speed will be set to default (1)

    EXIT STATUS:
                    0   if OK,
                    84  if problems.

USER INTERACTIONS
    ‘L’             key : enable/disable hitboxes and areas.
    ‘S’             key : enable/disable sprites.
    ‘B‘             key : enable/disable background
    ‘G‘             key : enable/disable grid
    ‘Q‘             key : close the window
    ‘SPACE‘         key : play/pause the simulation
    up_arrow        key : increase speed (max at x4)
    down_arrow      key : decrease speed (min at x0.25)
    right_arrow     key : reset speed to default (1)

SCRIPT FORMAT
    The script file describe the plane and the tower to use inside the program.
    The script has no limit in terms of object describe, but as to be written the following way :

    "A <start position X> <start position Y> <end position X> <end position Y> <speed int (Px/s)> <time before take off (s)>"
    OR
    "T <position X> <position Y> <radius (%)>"

    All the value describe between '<>' as to be positive integers

    All those value are in pixel, except for :
        - <speed int> : pixel per second
        - <time before take off> : second
        - <radius> : percentage of the window size

EXAMPLE
    ./my_radar -h
    ./my_radar scripts/script.rdr

REPORTING BUG
    Their is no bug
