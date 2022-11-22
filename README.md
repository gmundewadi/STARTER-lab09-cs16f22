
---
layout: lab
num: pa01
ready: true
desc: "Fun with Data and Plots"
assigned: 2022-11-28 13:00
due: 2022-12-05 14:00
---

# Goals for this lab

The goal of this lab is practice *insert learning goals*.  

We request that you DO NOT ask the staff to debug your code for you. They have been specifically instructed not to debug *for* you, but rather to *guide you* through the process of debugging your code yourselves.

# Instructions

## Step 1: Getting Ready

1. Go to github and find a repo for this lab assigned to your GitHub id.
2. Log on to your CSIL account.
3. Change into your `~/cs16` directory
4. Clone your empty lab09 repo into your `~/cs16` directory.
5. In your empty repo, do `git checkout -b main` to establish that you are on the `main` branch as your default branch.

## Step 2: Obtain the starter code

The starter code is in this repo:

* <insert starter code link here>

The URL for cloning this repo is this: `git@github.com:{{site.github_org}}/STARTER-{{page.num}}.git`

Previous labs contain instruction for the process of:
* Adding a `starter` remote for this repo
* Pulling the code from that `starter` remote into your own repo.

Please do those steps now, and then do a `git push origin main` to populate your own repo with the starter code.

If you need help with these steps:
* First consult previous labs for more detailed instructions.   
* Then, if you are still having trouble, ask the staff for help during discussion section or office hours.

Once you've populated your repo, typing the `ls` command should show you the following files in your current directory

```
% ls
2008CompilationData.csv		dataManipulationFuncs.h
Makefile			graphingTool.cpp
dataManipulationFuncs.cpp	matplotlibcpp.h
```

## Step 3: Implement the functions

### Assignment Background
This programming assignment investigates oceanic carbon and oxygen isotope ratios over time. These ratios are important since they can help us identify moments of significant temperature change. For example:
-  $\delta$<sup>18</sup>O: oxygen-18 / oxygen-16
-  $\delta$<sup>13</sup>C: carbon-13 / carbon-12

Larger values for $\delta$<sup>18</sup>O indicate lower temperatures

Smaller values for $\delta$<sup>13</sup>C indicate higher temperatures. 

For more detailed information regarding this assignment, feel free to visit: http://www.discoveringcs.net/7_data_analysis/project7.1.pdf


### Step 3a: CSV Parsing (Required)
You will find that all the data is given in csv (comma separated values) format, in three main data types. 

- First Column: time (Ma - Millions of Years Ago)
- Second Column: $\delta$<sup>18</sup>O
- Third Column: $\delta$<sup>13</sup>C

###### Your Task

When working with large amounts of data, it is often useful to store it in a data structure such as a vector. 

In ```dataManipulationFuncs.cpp``` there is a function with the declaration:
``` vector<vector<double>> parseData(const string pathToFile, size_t numCol); ```

Your job is to implement this function by parsing the csv data into a ```vector<vector<double>>```

It takes in two arguments:
- ```const string pathToFile```: the relative file location of the csv data.
- ```size_t numCol```: The number of columns stored by the data. 

It outputs:
- ```vector<vector<double>>```: This structure which is returned should be a vector of all the columns, where each column is also represented as a vector. 

Notice there are some data entries that are missing for some rows. When parsing the data, if a row is missing data from any column, do not include it in the final data structure. 

Finally, your function should also check for errors with the file opening process. 

### Step 3b: Plotting (Extra Credit)



### Step 3c: Filtering (Extra Credit)

### Step 3d: Smoothing (Extra Credit)

## Acknowledgements

This programming assignment is based off an exercise from "Discovering Computer Science: Second Edition".

- http://www.discoveringcs.net/7_data_analysis/project7.1.pdf
