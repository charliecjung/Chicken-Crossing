<h1> Development Log: </h1>

Started working on the program. I was successful in getting a frog sprite in the up, down, left, and right directions to be displayed upon pressing the arrow keys.
Currently working on the movement of the frog and the edge cases (such as the boundaries of the screen). Left and the Top Screen appear to be working but the right side and bottom edge are troublesome.

Debugging by using ofDrawLine() and ofPolyLine() will try to update with <i> Google C++ styling guide </i> if enough time remains. Writeup concluded for now.

Experimented with main.cpp where I would create a <b> ResourceManager </b> object and pass it into ofRunApp(). Unfortunately, my program would fail so I resorted back to
passing a new ResourceManager() everytime the program is run. 

I was able to fix the edge cases by printing lines with the ofDrawLine() functions that enabled me to print the x,y,screenWidth,screenHeight of my program for debugging purposes.
All in all, it went <i> well </i>.

<h2> Task Two -- Making the Background Image with Gimp </h2>

<b> Hold up </b>. I realized why my frog was not displaying in the center-bottom of my screen.
I was setting all the frog's <b> (Player's) </b> variables in a constructor but I was
creating a Player object on the stack... Yup, I created a setup() function for Player
to initialize its own variables before the program plays any sound. <i> Near the start
of the program :) </i>

<i> Also, I no longer need to make a backgroundImage using <b> GIMP </b> Found one on
opengameart.org. On to the next adventure... </i>


<h2> Finishing up for Tuesday... </h2>

I'm using <i> hardcoded constants </i> for the starting position as a placeholder for the frog's starting position (since screen dimensions aren't created until idk :(). Sound
I have set up the program to exit once the frog has reached the top of the screen (y = 0) because that means the frog has crossed the road successfully without dying.
This next week, I will try to add enemies such as cars and maybe use sorting algorithms to switch them up using external api's. 
<i> Making custom enemies using <b> JSON data </b> would be particularly interesting... </i> Anyways, off to the test cases!








<b> Creative Commons: </b>
https://creativecommons.org/licenses/by-nc/3.0/

Background Remix: https://freesound.org/people/Timbre/sounds/424028/

Original Background Sound: https://freesound.org/people/Suburbanwizard/sounds/423294/

Background Image: www.davidstenfors.com


<b> Get attribution from Frog sprites </b>

