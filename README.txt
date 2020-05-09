BlisyTV Read me
-----------------------
This is a tool meant to assist in Fire Red and Leaf Green retail RNG abuse.

I will go over each section. 

-------------------
Settings
-------------------
Intro timer in MS - In FRLG, you must wait until the entire intro is played out before you hit A to continue. This is about 35000 milliseconds, aka 35 seconds. However, waiting slightly less or slightly longer can drastically change the seed you hit. I default this box to 35000, but change it in Milliseconds to whatever value you need to wait to hit your current seed.
--------------------
Abra Frame - This check box and spinbox combo is for seed verification in FRLG. Sometimes, when you have to wait a long time for a frame in these games it is best to verify you hit the correct seed by receiving an abra from the gamecorner at a really low frame. I default it to 800. You check the box if you are using the abra frame, if not leave unchecked. This ONLY outputs into the flowtimer section. Nothing else.
--------------------
Console Select - This determines the framerate value. On a gba the framerate is 59.7275 per second, and on a NDS-GBA mode, it's 59.6555 frames per second. 
--------------------
Game Select - There's 3 options, FireRed 1.0, FireRed 1.1, and LeafGreen. This is because there is a few frames of lag generated before your seed starts, and it's different based on game. 
--------------------
Delay - This box is editable and also changes with the dropdown box next to it. The delay is changed to a default value for whichever method you're doing. This is basically how many frames occur when you hit the final "a" press to receive or generate a Pokemon. Almost all stationary Pokemon in FRLG have a -20 value, so that is the default, but you can change it manually if you need. SID is -249 because that's the lag of the secret ID generation in the US games, but it's different in the other languages so it's also editable. the sweet scent value is universal across all sweet scents and game versions, so they are not editable. 
--------------------


--------------------
TeachyTV
--------------------
This is a section to help you calculate how many frames you should spend in teachytv.
--------------------
TeachyTV Target
--------------------
In the "Target Frame" Box, you input your target frame. "In the Out of TV Frames" box, you input how many frames you're willing to spend out of the TV. Minimize this number best you can, to have the shortest wait time possible. 

Once you hit calculate, it will spit four values out. Total frames, inside TV frames, Total MS, and inside TV MS. Total frames is the amount of frames you will spend in the game from boot up to A press to start encounter, and it's for your first timer. Inside tv frames is how long you will spend in the TV. The corresponding values in MS are for the same thing. 
--------------------
Adjustment
--------------------
The adjustment tab is fairly self explainatory. You type what frame you hit, hit the calculate button, and then it tells you how many frames and MS to adjust your timers by. If it's a negative value you subtract, if it's a positive value you add.
--------------------
Flowtimer
--------------------
Flowtimer is the best timer to use for FRLG because of its accuracy, however, the format in which it sets its timer up is extremely annoying to add or subtract frames to, so clicking the update button after either calculating your first target or your adjustment target will output your values to copy and paste into flowtimer. Its total MS, then intro timer, then abra frame if you're using abra frame. The copy buttons underneath copy the values.

---------------------



---------------------
Flowtimer Converter
---------------------
This is a tab meant to convert frames and adjustments to the flowtimer format, which is MS. 

Target frame is where you input which frame you want to hit, and when you hit calculate it converts the frame into milliseconds, adds your pretimer to it, and outputs in the flowtimer format which is totalframe/introtimer/abraframe(if using abraframe). The frame hit box is where you input what frame you hit, and when you click calculate it tells you how many frames you should adjust by. If negative it means to subtract that many frames fro your taget, if positive it means add that many frames to your target. Clicking update and copy applies that frame difference, converts it to MS, and copies it to your clipboard to paste into flowtimer.