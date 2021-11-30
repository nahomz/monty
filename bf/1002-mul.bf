#Make the first cell (Cell 0) hold a value of 48 
>++++ ++++ @p1
[
<++++ ++ @0
>>++++ ++ @2
>++++ ++ @3
<<- @1
]

#substract 48 from it to remove the ascii value
,       # read character and store it in p1
> @2
[
-
<- @a1
>
]


,       # read character and store it in p2
# substract 48 from it to remove the ascii addition
>@3
[
-
<- @a2
>
]
<

@2 # currently at
[           # enter loop
<   @1
[
<+          @0
>>>+        @3
<<-      @1
]
>-  @2
#copy the values at three back to 1
> @3
[
<<+ @1
>>-@3
]
< @2
]

<< @0
. #print the final result
