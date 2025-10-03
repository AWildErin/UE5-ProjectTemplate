# File Structure
This folder contains all the modules used by your game. The general workflow we work with is this, however it is perfectly fine to deviate where you see fit
so long as the code base does not become messy to maintain or navigate.

- (Name)Game
    - Actors
        - All actors live in this folder and may be organised by sub folders too  (With the exception of player classes as they live in a another folder)
        - It is also acceptable to store things specifically used by actors and nothing else
    - AI
        - All AI related classes such as pawns and their movement components, behaviour tree classes, etc. It's acceptable to use subfolders.
    - Animation
        - All animation related classes such as notifiers, anim instances, etc. It's acceptable to use subfolders.
    - Blueprint
        - General blueprint classes such as function libraries and other various blueprint specific stuff
    - Character
        - An optional folder for all base pawn/character related classes that are not specific to AI or the player, but may be used by AI or the player.
    - Core
        - All core classes for the module, such as classes used by UEngine, Base game mode etc.
        - Generally, custom game modes should be done in Blueprint, or if they must be done in C++ they can live here.
    - Misc
        - All miscellaneous classes and headers, for instance gameplay tags, physics types, utilies etc.
    - Player
        - All classes related to the player, such as movement, controller, cheat manager etc.
    - UI
        - All classses related to UI, such as AHUD, blueprint widgets, etc.

- (Name)Editor
    - The editor folder doesn't have a general guideline as this module differs depending on the games need.
