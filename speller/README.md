# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

A pneumoconiosis caused by inhalation of very fine silicate or quartz dust.

## According to its man page, what does `getrusage` do?

getrusage() returns resource usage measures for who, which can be one of the following:

- RUSAGE_SELF
    Return resource usage statistics for the calling process, which is the sum of resources used by all threads in the process.

- RUSAGE_CHILDREN
    Return  resource  usage  statistics  for  all  children  of the calling process that have terminated and been waited for.  These statistics will
    include the resources used by grandchildren, and further removed descendants, if all of the intervening descendants waited on  their  terminated
    children.

- RUSAGE_THREAD (since Linux 2.6.26)
    Return resource usage statistics for the calling thread.

## Per that same man page, how many members are in a variable of type `struct rusage`?

16

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

before and after are defined by calling getrusage, which returns 16 members. We pass by reference instead of value to avoid making a copy of these variables,
which will take up a lot of memory and time because they contain 16 members.
Instead, with reference, the computer just goes to where they are alreadt stored in memory



## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

Uses fgetc to iterate over each character in the input text file. It checks to only allow alphabetic chars or apostrophes.
If the word is too long or contains a digit, it is ignored. Whenever a valid word is found, word count is increased by 1, rusage is recorded, word is put through check function to see if it is spelled correctly,
after rusage is recorded and time is calculated. If the world is misspelled, it is printed and the misspelled word counter is increased. Index is set back to 0 and it loops through for the next word.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

This allows us to quickly check that the input is valid. We only allow words with alphabetical characters or apostrophes and ignore input with digits

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

We do not want to allow the  dictionary or words being checked to be changed. This could lead to unpredicatable behavior or results.
Declaring them with const ensures they will not be changed.


