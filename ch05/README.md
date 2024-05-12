# Chapter 5: Optimizing Program Performance


First need to make sure of program working correctly under all possible conditions, running fast but incorrect is not what you want, but in some cases like processing video frames or network packets you need program to run as fast as possible, this chapter is about running program faster and optimize it.

for writing an efficient program requires several types of activities, first you must choose an appropriate set of algorithms and data structures, second must write source code that the compiler can effectively optimize to turn into efficient executable code, for second one it is important to understand the capabilities and limitations of optimizing compilers, minor changes can make huge differences in compiler optimization, in C, performing pointer arithmetic and casting make it harder to compiler to optimize(I don’t know this is still true or not, compilers are constantly changing), third thing is to divide program or task into some portions and run them in parallel(chapter 12)

compiler(gcc and clang) can optimize code few level, `-Og` will apply some basic optimization,  
`-O1` or `-O2, -O3` will apply more extensive optimization which make program hard to debug and so on.. but `-O1` is the standard. writing nice C code is better than writing shitty code and try to optimize it with compiler.

I feel guilty of this, I think it is better to read new book on optimization, because this is field of constantly changing. so ....