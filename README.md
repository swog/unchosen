# unchosen 

### cheat setup using visual studio
1. Download repository
2. Open visual studio
3. Create new Win32 project, name it whatever
4. Click next, choose dll as the application type
5. Check empty project, click finish
6. Change the configuration to release instead of debug
7. Right click on the project, click properties, change the character set to "Use Multi-Byte Character Set"
8. Click apply
9. Right click Source files filter, click Add>Existing Item...
10. Navigate to the unchosen/cheat folder, type "\*.cpp" in the search bar, hit enter.
11. Press ctrl+a to select all items, click add
12. Open the junk.h file in visual studio, edit some of the strings
13. Press ctrl+shift+b
14. Navigate to the release folder, open the injector

### injector setup using visual studio
1. Finish the cheat setup tutorial
2. Right click on your solution, click Add>New Project...
3. Click Win32 Console Application, name it whatever, click ok
4. Click Next, check Empty Project, click Finish
5. Right click on the source files filter, click Add>Existing Item...
6. Navigate to the unchosen/injector folder, select the injector.cpp file, click add
7. If you havent edited the junk.h file, do so now
8. Press ctrl+shift+b
9. Navigate to the release folder, open the executable with csgo open
