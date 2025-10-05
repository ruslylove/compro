---
theme: seriph
background: https://images.stockcake.com/public/9/9/8/9985c91b-b967-4e97-a28d-f7adcf98d01b/cosmic-puppy-adventure-stockcake.jpg
transition: slide-left
layout: cover
title: PA - The Cosmic Pet Simulator!
class: lab
routeAlias: pa
---

# Programming Assignment: <br>The Cosmic Pet Simulator!
## {{ $slidev.configs.subject }}
### Semester {{ $slidev.configs.semester }}
#### Presented by {{ $slidev.configs.presenter }}
---
hide: true
---

## 🚀 C Programming Assignment 🚀
## The Cosmic Pet Simulator!

**Posted:** September 23, 2025

**Due:** Friday, October 10, 2025, by 11:59 PM

---

## The Mission 🛰️

Greetings, Programmers!

Our deep space probes have discovered a mysterious egg from another world. Your mission is to build an environment to hatch this egg and raise the creature within.

**Your Goal:** Create a complete, interactive, text-based virtual pet simulator in C. You'll be responsible for the health and happiness of your very own alien pet.



---

## Core C Concepts 🧠

This assignment will challenge you to apply your knowledge of fundamental C concepts:

- **`struct`**: To define the very essence of your Cosmic Pet.
- **Pointers**: To interact with and modify your pet's state across different functions.
- **Functions**: To create modular, reusable code for all the pet's actions.
- **Arrays**: To manage collections of items, text, or animations.

---

## The Creative Challenge ✨

While the core simulation is key, this is also a test of your **creativity**. A significant portion of your grade is based on the unique features you add.

**Think like a game designer!** What would make this simulator more fun, challenging, or engaging? Your goal is to impress us with your ingenuity!

---

## Creative Ideas to Get Started...

Here are some ideas to spark your imagination (but unique ideas are highly encouraged!):

- **Advanced Pet Stats**: Add attributes like *Energy*, *Intelligence*, or *Weight*. How do they interact?
- **Inventory System**: Create an array of structs for different foods or toys.
- **Training System**: Teach your pet tricks that you can show off later.
- **Mini-Games**: Launch a number-guessing or rock-paper-scissors game for a happiness boost.
- **Save/Load Functionality**: Use file I/O to save and resume the game.
- **Dynamic Events**: Create random events like meteor showers or passing comets.
- **High-Score Leaderboard**: Implement a system to calculate and save scores.

---

## Getting Started

Here are some code skeletons to help you begin.

### Hint: Advanced Pet Stats

Modify the `CosmicPet` struct and update the stats in your game loop.

```c
// In the struct definition
typedef struct {
    char name[50];
    int hunger;
    int happiness;
    int age;
    int energy; // New stat!
} CosmicPet;

// In your game loop, after an action:
pet->energy -= 5; // Playing uses energy
```

---

## Hint: Inventory System

Create a new `struct` for an item, then create an array of those items.

```c
// A new struct for food items
typedef struct {
    char name[30];
    int hunger_effect;
    int happiness_effect;
} Food;

// In main(), create an inventory
Food inventory[2] = {
    {"Astro-Kibble", -15, 5},
    {"Cosmic-Goo", -5, 15}
};
```

---

## Hint: Save/Load Functionality

Use `fopen`, `fwrite`, and `fread` to manage game state in a binary file.

```c
// A function to save the game state
void saveGame(const CosmicPet *pet) {
    FILE *saveFile = fopen("pet.sav", "wb");
    if (saveFile != NULL) {
        fwrite(pet, sizeof(CosmicPet), 1, saveFile);
        fclose(saveFile);
    }
}

// A function to load the game state
void loadGame(CosmicPet *pet) {
    FILE *loadFile = fopen("pet.sav", "rb");
    if (loadFile != NULL) {
        fread(pet, sizeof(CosmicPet), 1, loadFile);
        fclose(loadFile);
    }
}
```

---

## Hint: Leaderboard Logic

* Maintain a top-10 leaderboard.

* When a game ends, if the score is high enough, it must be inserted into the correct rank, shifting other scores down.

* The main title screen must have an option to view the high scores without starting a new game.

**Struct for High Scores**:

```c
#define HIGH_SCORE_ENTRIES 10
#define SCORE_FILE "cosmic_scores.dat"

typedef struct {
    char playerName[50];
    int score;
} HighScoreEntry;
```
---

## Hint: Main Menu Structure

```c
int main() {
    loadHighScores(); // Your function to load scores from the file

    while (1) {
        // showTitleScreen();
        printf("1. Start New Journey\n");
        printf("2. View High Scores\n");
        printf("3. Quit\n");

        int choice;
        // Get user's menu choice...

        if (choice == 1) {
            runGame(); // This function contains your main game loop
        } else if (choice == 2) {
            displayHighScoreBoard();
        } else {
            break; // Exit the loop to quit
        }
    }
    return 0;
}
```
---

## Grading Rubric 📊

Your final score will be determined as follows:

  - **60% - Core Functionality**: The base simulator works as expected. The pet hatches, grows, and responds correctly to commands. Game-over and win conditions are functional.
  - **20% - Creativity & Extra Features**: The quality, originality, and implementation of the new features you add to the game.
  - **20% - Code Quality & Comments**: Your code is clean, well-organized, and easy to read, with comments explaining your logic.
  - **🎁 Bonus Features**: Up to 10 bonus points (**extra 10% of the final grading**) for exceptional creativity (e.g., advanced pet AI, multiple mini-games, ASCII art animations).

---
layout: two-cols
---

## Submission ✅

Your submission must be a single ZIP file containing the following:
1.  **Source Code**:
    *   Your single, well-commented `cosmic_pet.c` file.
2.  **Report (PDF format)**:
    *   **Programming Design**: Include flowcharts for your main game loop and at least two other key functions (e.g., `feedPet`, a mini-game).
    *   **Instruction Manual**: A clear, user-friendly guide on how to compile and play your game, explaining all commands and features.
:: right ::

3. **Video Demonstration**:
* Each team must submit a **Youtube link** of a 3-5 minute video clip demonstrating their project.
* **Introduction**: Both team members should appear on camera and introduce themselves and the project. Briefly explain the creative features you added.
* **Live Demonstration**:
    Show the game starting up and the main menu options.
    * Demonstrate all core features: feeding, talking, and playing your mini-game.
    * Show a game ending (win, lose, or quit).
    * Display the final score calculation and show how the high-score board is updated.

- **Where:** Submit the ZIP file to the course portal.
- **When:** Before the deadline on **27 October 25**.

---

## Good Luck\!

We are incredibly excited to see the unique cosmic companions you all create.

**Have Fun\!** 👽👾
