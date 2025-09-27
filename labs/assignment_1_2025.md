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

## Grading Rubric 📊

Your final score will be determined as follows:

  - **60% - Core Functionality**: The base simulator works as expected. The pet hatches, grows, and responds correctly to commands. Game-over and win conditions are functional.
  - **20% - Creativity & Extra Features**: The quality, originality, and implementation of the new features you add to the game.
  - **20% - Code Quality & Comments**: Your code is clean, well-organized, and easy to read, with comments explaining your logic.

---

## Submission ✅

Your submission must be a single ZIP file containing the following:
1.  **Source Code**:
    *   Your single, well-commented `cosmic_pet.c` file.
2.  **Report (PDF format)**:
    *   **Programming Design**: Include flowcharts for your main game loop and at least two other key functions (e.g., `feedPet`, a mini-game).
    *   **Instruction Manual**: A clear, user-friendly guide on how to compile and play your game, explaining all commands and features.
    *   **Advertising Banner**: A short, creative "advertisement" for your game. Highlight the unique features you implemented and make it sound exciting!

- **Where:** Submit the ZIP file to the course portal.
- **When:** Before the deadline on **TBD**.

---

## Good Luck\!

We are incredibly excited to see the unique cosmic companions you all create.

**Have Fun\!** 👽👾
