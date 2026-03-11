# Computer Science and Digital Engineering

**Module:** Computer Science and Digital Engineering  
**Degree:** BSc Computer Science and Digitization

---

## Overview

This repository contains two tasks completed as part of the Computer Science and Digital Engineering module:

- **Task 1:** C++ program for sentiment analysis with ASCII art visualization
- **Task 2:** CAD design of a 3D measuring cup using FreeCAD

---

## Task 1 – C++ Sentiment Analysis

A program that analyses the sentiment of user-entered text and displays the result using ASCII art shapes.

### How it works
- User enters a sentence or paragraph
- Words are tokenized, lowercased, and stemmed
- Each word is matched against predefined positive/negative word lists
- Sentiment is classified as Positive, Negative, or Neutral
- Result is displayed with a matching ASCII face

### How to run

```bash
g++ -o sentiment sentiment_analysis.cpp
./sentiment
```

### Example output

```
Enter a sentence: I love this amazing day

--- Sentiment Analysis Result ---
Overall Sentiment: POSITIVE (score=2)

     .-"""-.     
    .'  _ _  '.   
   /   (o o)   \  
  |    ( ^ )    | 
   \  '-----'  /  
    '.______.'    
       POSITIVE   
```

---

## Task 2 – CAD Design: Measuring Cup (FreeCAD)

A 3D model of a measuring cup designed in FreeCAD for use in a digital cooking game.

### Design steps
1. Project setup in Part Design Workbench
2. 2D sketch with concentric circles (outer: 8cm, inner: 7cm)
3. Pad (extrude) to 10cm height
4. Pocket operation to hollow interior (9.5cm depth)
5. Handle added and smoothed with Fillet tool
6. Appearance modified with translucent blue colour

### Export formats
Compatible with STL and OBJ for use in game engines.

---

## Files

| File | Description |
|------|-------------|
| `sentiment_analysis.cpp` | C++ sentiment analysis program |
| `report.pdf` | Full assignment report with code, screenshots, and CAD walkthrough |

---

## Technologies

- C++ · g++ compiler
- FreeCAD (Part Design Workbench)
