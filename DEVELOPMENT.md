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


<h1> 1:02 AM Friday </h1>

After many tribulations of reinstalling VStudio and recloning the project. I realized that deleting the <i> obsolete </i> constructor caused my program to work again.
I am not entirely sure how my debugging process went but it was extremely exhausting.

Will be back...

<h1> April 22, 2018 (Sunday) </h1>

Finally fixed a bug with the program not running at all. I wasn't called ofBaseApp's method properly with setup(). (Created a custom SetUp() function due to Google's styling guide)
I have now removed the ofxActionManager and replaced it with ofx2DFigures because I believe it enables me to track collisions with enemies and the player.
Updating a PUSH->Github.com.

Updated images with pictures of a chicken because I couldn't find the owner of the frog's original images. <<b>Royalty creds... </b>>

<b> This is important for next PUSH: https://github.com/vanderlin/ofxBox2d/blob/master/example-ShapeTexturing/src/ofApp.cpp

<h1> April 24, 2018 10:46 PM (Tuesday) </h1>

Replaced my Move() functions with std::Max and std::Min's. A whole lot simpler.

<h1> After 12 </h1>

Finished almost the whole game. Should start working on test cases and how to stop the car's speed from becoming 0. Other than that
we could implement <i> powerups </i> and testcases using <b> Catch.hpp </b> All done for now!


<h1> Final Tasks </h1>


:heavy_exclamation_mark: Change <Enemy> to <Enemy*>

:heavy_exclamation_mark: check getter and setter whether they should be public or private

:heavy_exclamation_mark: Implement EnemyManager to create Enemy objects (Wrapper).

:heavy_exclamation_mark: Create powerups

:heavy_exclamation_mark: Implement Gameover() ResetGame(), KillPlayer()

:heavy_exclamation_mark: Make several levels. (Need to find more background images).

:heavy_exclamation_mark: Add methods to delete pointers.

:heavy_exclamation_mark: enemyList, powerup1, currentEnemy, enemyList_

:heavy_check_mark: Find pickup images from opengameart.org

:heavy_check_mark: std::max and min for Move() logic.

:heavy_check_mark: moving beyond the screen for the Player (chicken)

:heavy_check_mark: Random() generator for speed

:heavy_check_mark: Ensure that enemySpeed != 0




<h1> Credits: </h1>

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

Powerup Items supplied by Ravenmore: https://opengameart.org/content/fantasy-icon-pack-by-ravenmore-0
(His portfolio site: http://dycha.net)




