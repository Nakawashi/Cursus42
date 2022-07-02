# Push_swap

*Because Swap_push isn’t as natural*

## Summary:
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. </br>
To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.</br>

*Version: 6*

## Authorized Operations
`sa (swap a): Swap the first 2 elements at the top of stack a.` <br>
Do nothing if there is only one or no elements.<br>
`sb (swap b): Swap the first 2 elements at the top of stack b.`<br>
Do nothing if there is only one or no elements.<br>
`ss : sa and sb at the same time.`<br>
`pa (push a): Take the first element at the top of b and put it at the top of a.`<br>
Do nothing if b is empty.<br>
`pb (push b): Take the first element at the top of a and put it at the top of b.`<br>
Do nothing if a is empty.<br>
`ra (rotate a): Shift up all elements of stack a by 1.`<br>
The first element becomes the last one.<br>
`rb (rotate b): Shift up all elements of stack b by 1.`<br>
The first element becomes the last one.<br>
`rr : ra and rb at the same time.`<br>
`rra (reverse rotate a): Shift down all elements of stack a by 1.`<br>
The last element becomes the first one.<br>
`rrb (reverse rotate b): Shift down all elements of stack b by 1.`<br>
The last element becomes the first one.<br>
`rrr : rra and rrb at the same time.`<br>

## Usage

1. make..
