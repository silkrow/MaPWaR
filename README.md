# MaPWaR

This is a game based on C & SDL.

## Introduction

In the game, the player will act as a commander who's trying to win a battle in a region. 

The region is rectangle shaped, with grids specifing little areas. At the beginning, both 

player and computer will have it's own *commander base* at one random square in the most 

left/right edge of the region, at each round, the player can contact with his/her soldiers 

to send commands, and at the same time decide which type of new soldiers does he/she need 

as backups. The whole fighting process is automatically calculated base on the landform as 

well as the property of the soldiers. All player can see is a rectangle area as map, with 

parts of visible grids on it, the visibility of places could only be found out by the 

communication with soldiers. The *commander base* has it's own real time sight, and can be

resettled as desired.

Satisfying any of the following requirement will be considered winning:

1. Destroy opponent's *commander base*.

2. Occupying one of two opponent's *winning fortress* for enough rounds.

3. The opponent resigned.

4. The opponent reaches any losing condition.

## Basic RULES

### Player

Each round, the player will choose the new type of soldier and amount he/she wants for the 

next backup, and he/she should read the information received from communicators, and send 

commands to them. 

### Moving

Each type of soldier has its own speed influenced by the landform, they'll follow the 

instruction and move to the destination automatically, unless encountering enemies, which 

will cause them to stop and fight. 

After some rounds(Depend on the specific kind of soldier/unit the commander ordered), 

backup forces will join the map from somewhere near the birth place of the *commander base*.

### Fire!

All fights will be automatically done, but the calculated infomation of fire power last round 

will be feeded back to commander each round for future decisions(As well as the member 

situation). Generally, a group of troop will have a life line indicating its scale, whenever

the number is lower than some threshold, it will be considered as **unit loss** and the self 

recovering life line will never recover to high then this threshold again.

### Communication

At the beginning, the player has 6 communication devices, afterwards, communication devices

will be supplied as backups. The soldier that holds the communication device will provide a 

visible area(and can send command to).

## Types of soldier and their property

### commander base

### scout

## Types of landform

### hill

### mountain

### river

### forest

### plain




