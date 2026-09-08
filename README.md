# Student Information
- **Name:** Barira Najam
- **Registration Number:** 577187

## Program Descriptions & Tasks

- **Task 1:** This program initializes an array with specific values, modifies the third element, and uses a for loop to display all elements separated by spaces.
- **Task 2:** This program reads five integers into an array using one loop and calculates their cumulative sum using a second loop.
- **Task 3:** This program defines a `Student` class with `rollNumber` and `marks` data members and a display function to demonstrate object instantiation, member assignment, and independence between object instances.
- **Task 4:** This program reads 8 integers into an array to find and display both the maximum and minimum values along with their first occurrence indices.
- **Task 5:** This program reads 8 integers into an array to compute and display the largest and smallest values alongside their respective indices, reporting the first occurrence if duplicates exist.
- **Task 6:** This program reads 6 integers into an array and reverses the elements in place without utilizing any auxiliary array.
- **Task 7:** This program reads 10 integers into an array and rearranges the unique elements to the beginning while preserving their original order, displaying the unique values and their total count.

## Task 3 Test Results
- **Initial State (s1.marks = 75, s2.marks = 90):** Both objects print their respective initial `rollNumber` and `marks` correctly.
- **Modified State (s1.marks changed to 80):** When `s1.marks` is updated to 80 and both objects are displayed again, `s1.marks` becomes 80 while `s2.marks` remains unchanged at 90.
- **Explanation:** `s1` and `s2` are separate instances of the `Student` class, meaning each object maintains its own distinct memory allocation for data members (`rollNumber` and `marks`). Modifying a member of one object does not affect the other.