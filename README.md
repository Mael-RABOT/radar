## NAME

&emsp;&emsp; my_radar

## SYNOPSIS
&emsp;&emsp; Air traffic simulation panel

## DESCRIPTION

&emsp;&emsp; ./my_radar [OPTIONS] path_to_script.
&emsp;&emsp; path_to_script: The path to the script file.

&emsp;&emsp; **OPTIONS**
&emsp;&emsp;&emsp; -h<br>
&emsp;&emsp;&emsp;&emsp; display the help<br>

&emsp;&emsp;&emsp; -R<br>

&emsp;&emsp;&emsp;&emsp; disable sprite rotation<br>

&emsp;&emsp;&emsp; -L<br>

&emsp;&emsp;&emsp;&emsp; start the simulation with hitboxes and areas disabled<br>

&emsp;&emsp;&emsp; -S<br>

&emsp;&emsp;&emsp;&emsp; start the simulation with sprites disabled<br>

&emsp;&emsp;&emsp; -B<br>

&emsp;&emsp;&emsp;&emsp; start the simulation with background disable<br>

&emsp;&emsp;&emsp; -G<br>

&emsp;&emsp;&emsp;&emsp; start the simation with the grid enable<br>

&emsp;&emsp;&emsp; -M [VALUE]<br>

&emsp;&emsp;&emsp;&emsp; start the simulation with a given speed<br>

&emsp;&emsp;&emsp;&emsp;&emsp; the VALUE as to be a positive integer between 1 and 4<br>

&emsp;&emsp;&emsp;&emsp;&emsp; the default value is set to 1<br>

&emsp;&emsp; **EXIT STATUS**<br>

&emsp;&emsp;&emsp; 0 Successful program execution,<br>

&emsp;&emsp;&emsp; 1 Usage, syntax or file error.<br>

## USER INTERACTIONS
&emsp;&emsp; 'L' key: enable/disable hitboxes and areas<br>
&emsp;&emsp; 'S' key: enable/disable sprites<br>
&emsp;&emsp; 'B' key: enable/disable background<br>
&emsp;&emsp; 'G' key: enable/disable grid<br>
&emsp;&emsp; 'Q' key: close the window<br>
&emsp;&emsp; 'SPACE' key: play/pause the simulation<br>
&emsp;&emsp; 'up_arrow' key: increase speed<br>
&emsp;&emsp; 'down_arrow' key: decrease speed<br>
&emsp;&emsp; 'right_arrow' reset speed to 1<br>

## SCRIPT FORMAT
&emsp;&emsp; The script file describe the plane and the tower to use inside the program.<br>

&emsp;&emsp; The script has no limit in terms of object describe, but as to be written the following way:<br>

&emsp;&emsp; ""A <start position X (Px)> <start position Y (Px)> <end position X (Px)> <end position Y (Px)> <speed int (Px/s)> <time before take off (s)>""<br>

&emsp;&emsp; OR<br>

&emsp;&emsp; "T <position X (Px)> <position Y (Px)> <radius (%)>"<br>

<br/>
&emsp;&emsp; All the value describe are positive integers<br>

&emsp;&emsp; ALL those value are in pixel, except for:<br>

- <speed int>: pixel per second<br>
- <time before take off>: second<br>
- <radius>: percentage of the window size<br>

## EXAMPLE
&emsp;&emsp; ./my_radar -h
&emsp;&emsp; ./my_radar scripts/scripts.rdr

## REPORTING BUG
&emsp;&emsp; There is no bug

<br/><br/><br/>
<img src="sources/epitech.png" alt="Epitech Technology Logo" title="Epitech Technology Logo" width=300 height=100>
