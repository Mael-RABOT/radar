## NAME

&emsp;&emsp; my_radar

## SYNOPSIS
&emsp;&emsp; Air traffic simulation panel

## DESCRIPTION

&emsp;&emsp; ./my_radar [OPTIONS] path_to_script
&emsp;&emsp; path_to_script: The path to the script file

&emsp;&emsp; **OPTIONS**
&emsp;&emsp;&emsp; -h
&emsp;&emsp;&emsp;&emsp; display the help
&emsp;&emsp;&emsp; -R
&emsp;&emsp;&emsp;&emsp; disable sprite rotation
&emsp;&emsp;&emsp; -L
&emsp;&emsp;&emsp;&emsp; start the simulation with hitboxes and areas disabled
&emsp;&emsp;&emsp; -S
&emsp;&emsp;&emsp;&emsp; start the simulation with sprites disabled
&emsp;&emsp;&emsp; -B
&emsp;&emsp;&emsp;&emsp; start the simulation with background disable
&emsp;&emsp;&emsp; -G
&emsp;&emsp;&emsp;&emsp; start the simation with the grid enable
&emsp;&emsp;&emsp; -M [VALUE]
&emsp;&emsp;&emsp;&emsp; start the simulation with a given speed
&emsp;&emsp;&emsp;&emsp;&emsp; the VALUE as to be a positive integer between 1 and 4
&emsp;&emsp;&emsp;&emsp;&emsp; the default value is set to 1
&emsp;&emsp; **EXIT STATUS**
&emsp;&emsp;&emsp; 0 Successful program execution,
&emsp;&emsp;&emsp; 1 Usage, syntax or file error.

## USER INTERACTIONS
&emsp;&emsp; 'L' key: enable/disable hitboxes and areas
&emsp;&emsp; 'S' key: enable/disable sprites
&emsp;&emsp; 'B' key: enable/disable background
&emsp;&emsp; 'G' key: enable/disable grid
&emsp;&emsp; 'Q' key: close the window
&emsp;&emsp; 'SPACE' key: play/pause the simulation
&emsp;&emsp; 'up_arrow' key: increase speed
&emsp;&emsp; 'down_arrow' key: decrease speed
&emsp;&emsp; 'right_arrow' reset speed to 1

## SCRIPT FORMAT
&emsp;&emsp; The script file describe the plane and the tower to use inside the program.
&emsp;&emsp; The script has no limit in terms of object describe, but as to be written the following way:

&emsp;&emsp; ""A <start position X> <start position Y> <end position X> <end position Y> <speed int (Px/s)> <time before take off (s)>""
&emsp;&emsp; OR
&emsp;&emsp; "T <position X> <position Y> <radius (%)>"
<br/>
&emsp;&emsp; All the value describe are positive integers
&emsp;&emsp; ALL those value are in pixel, except for:
- <speed int>: pixel per second
- <time before take off>: second
- <radius>: percentage of the window size

## EXAMPLE
&emsp;&emsp; ./my_radar -h
&emsp;&emsp; ./my_radar scripts/scripts.rdr

## REPORTING BUG
&emsp;&emsp; There is no bug

<br/><br/><br/>
<img src="sources/epitech.png" alt="Epitech Technology Logo" title="Epitech Technology Logo" width=300 height=100>
