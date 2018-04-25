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



<h2> Fixed code according to <i> Google's C++ styling guide </i> rather than work on test cases. Why? Rubric doesn't mention <b> test cases </b> </h2>

Documented more code. Freshened up comments. Created "F1" commit for first final "commit".




<b> Creative Commons: </b>
https://creativecommons.org/licenses/by-nc/3.0/

Frog attribution: https://opengameart.org/node/76895
By <b> Shepardskin </b>: https://twitter.com/Shepardskin
"Remix of Chicken by Shepardskin"
to be used in Chick by Stendhal.


Background Remix: https://freesound.org/people/Timbre/sounds/424028/

Original Background Sound: https://freesound.org/people/Suburbanwizard/sounds/423294/

Background Image: www.davidstenfors.com

Cars Attribution: https://opengameart.org/content/2d-cars-pack (Carlos Alface)

<h1> Todo List </h1>

<b> Frog can go to the right and show up to the left of the screen </b>

<b> Suggestion for car's to be on the heap </b>

<b> Suggestion for pickup's to be on the heap </b>

<b> Cars should auto destruct off screen and be replaced by a new Enemy object </b>

<b> replace out of boundary should have if and else to account for left and right side </b>

<b> random generator for sign of speed_ </b>
<h1> 1:02 AM Friday </h1>

After many tribulations of reinstalling VStudio and recloning the project. I realized that deleting the <i> obsolete </i> constructor caused my program to work again.
I am not entirely sure how my debugging process went but it was extremely exhausting.

<h3> Edits that I will have pushed in the next commit </h3>
<b> Changing functions to be NormalCamelCase (<i>Thank Google's C++ styling guide </i>) </b>
<b> Changing the name of ResourceManager to Coordinator (Also have to change the compile name in .vcprojectx </b>

Will be back...

<h1> April 22, 2018 (Sunday) </h1>

Finally fixed a bug with the program not running at all. I wasn't called ofBaseApp's method properly with setup(). (Created a custom SetUp() function due to Google's styling guide)
I have now removed the ofxActionManager and replaced it with ofx2DFigures because I believe it enables me to track collisions with enemies and the player.
Updating a PUSH->Github.com.

Updated images with pictures of a chicken because I couldn't find the owner of the frog's original images. <<b>Royalty creds... </b>>

<b> This is important for next PUSH: https://github.com/vanderlin/ofxBox2d/blob/master/example-ShapeTexturing/src/ofApp.cpp

<h1> April 24, 2018 10:46 PM (Tuesday) </h1>

Replaced my Move() functions with std::Max and std::Min's. A whole lot simpler.

