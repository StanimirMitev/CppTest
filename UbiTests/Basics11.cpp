/*  C++ Basics 11
    
    The next questions are for STL:

    We have a sorted sequence of numbers : 1, 3, 5, 7, 8, 9, 10...
    What will be the most efficient STL container to use if : 

    1. We need to have a quick read access to any of the elements? Explain why.
    We can use a vector, O(1) read, data would be stored sequentially in memory.
    2. We need to quickly add/remove elements preserving the sorted sequence? Explain why.
    We can use std::set, impements a binary tree. This would ensure the ordering will be preserved when adding/removing elements
    3. Associate any of the elements with some data, for example name of a student? Explain why.
    We can use std::unordered_map, this would previde the exact beahaviour we desire - associating a key(number) to the name of the student.
    We can use std::maps, if we wish to preserve sorted property when inserting new values.

*/

void main(int argc, char* argv[])
{
}