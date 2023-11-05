# SPH[F]
SPHome (Station Portable Home [Failure]), is my solo project for HackNotts84!

## Inspiration
Wouldn't it be nice to grab some old retro hardware and make it your own personal home assistant? A quick reuse of old hardware turned into your own neat centre piece as well as a helpful tool that would show you general information; be it the current song you're listening to, or the weather outside, or even a little to-do list! 

Well, that was my hackathon idea. I didn't quite complete it, or get anywhere close to doing so due to the unexpected low level graphical nature of the PSP SDK, so I decided to turn my mess of an idea into an excuse to learn how to use the PSP SDK, and now my project is simply showing how far I came!

## What it does
Well, can register your inputs, render the player and move the player object accordingly.
There were to be asteroids that would fly down that the player would need to dodge, but 

## How I built it
I used the PSP SDK in C++, using VSCode as my interpreter.
For Debugging I alternated between moving the EBOOT.PBP game file to my PSP, as well as using PPSSPP, a PSP emulator, that can run EBOOT game files.

## Challenges we ran into
-My psp's cable split open which prevented me from moving files over to my psp for testing. It was quite discouraging at first, but I was able to borrow a cable for a little bit, but just for my early testing.

-I spent countless hours banging my head at code, trying to learn psp sdk's commands; I was challenged by the fact that there was no intelisense, and there were long slightly confusing functions like: sceDisplayWaitVblankStart();, which I needed to quickly understand to move forward. Typos were my biggest enemy. Forgot the last time an error in my code was caused by simple typos so it was hard to not get frustrated.

-Psp sdk was not recognised in VSCode, so there were no function descriptions with the parameters needed, or corrections/suggestions from the intellisense. My work was slowed drastically. I was battling out with giving up constantly, but the fact that I made things appear on my PSP was enough to keep me going. 12 year old me would have fallen down at the thought of that.

## Accomplishments that we're proud of

-Being able to keep moving as a solo dev, with myself to motivate me
-Understanding a bit more about how functions like "drawRect" and "clear" work, and how certain pixels are individually manipulated; diving a little bit into how graphics libraries are made.

-The only experience in graphical programming I have ever had before this was with SDL; so this was a bit lower level than I was used to. Being able to not be intimidated and keep moving is really something that makes me proud. I love a challenge.

-I suppose another thing is learning how to get started off with the psp sdk. It's something I never touched before today, and it was really exhilarating making every bit of progress.

## What we learned
Sometimes things not going to plan isn't necessarily bad.
My little retro home appliance idea was cool, bit its no use if I cant make it; so shifting my priority to maximising my learning here really made this more enjoyable.
My little controllable space ship may not be in line with my original idea, but I'm definitely closer to completing that idea!

## What's next for SPHF
Well frankly, I do want to have my own little home psp with cool api connections (IF POSSIBLE!), but I want to try and make my own game engine for the PSP!!!
Just for fun! I really really am interested in understanding more about low level graphics programming and this project really benefited me in how I can progress in that area.

