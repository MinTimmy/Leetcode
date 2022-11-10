# Insert
https://stackoverflow.com/questions/253380/how-to-insert-text-at-beginning-of-a-multi-line-selection-in-vi-vim
1. Press **Esc** to enter 'command mode'
2. Use **Ctrl+V** to enter visual block mode
3. Move **Up/Downto** select the columns of text in the lines you want to comment.
4. Then hit **Shift+i** and type the text you want to insert.
5. Then hit **Esc**, wait 1 second and the inserted text will appear on every line.

```c++
cout << 1;
cout << 2;
cout << 3;
```
```c++
std::cout << 1;
std::cout << 2;
std::cout << 3;
```
# Append
https://vim.fandom.com/wiki/Inserting_text_in_multiple_lines
1. On a character in the first line, press Ctrl-V (or Ctrl-Q if Ctrl-V is paste).
2. Press jj to extend the visual block over three lines.
3. Press $ to extend the visual block to the end of each line.
4. Press A then space then Ctrl-R then + then Esc.
```
First.
This is the second line.
The third
```
```
First. Hello world.
This is the second line. Hello world.
The third. Hello world.
```

# Search and replace
https://vim.fandom.com/wiki/Inserting_text_in_multiple_lines
* <mark>: s/^/new text /</mark>	     Insert "new text " at the beginning of the line.
* <mark>: s/$/ new text/</mark>	 Append " new text" to the end of the line.
* <mark>: s/green/bright &/g</mark>	Replace each "green" with "bright green" in the line.


# insert spaces/tabs in text
```
Regular space: &nbsp;
Two spaces gap: &ensp;
Four spaces gap: &emsp;
```