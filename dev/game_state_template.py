
# # # # # # # # #
#  DEPRICATED   #
# # # # # # # # #

import sys

if len(sys.argv) <= 1:
    print("Expected 1 argument or more state names as arguments")
    exit()

args = sys.argv[1:]

words = [s.lower().split() for s in args]
print(words)
snake_case_list = ["_".join(i) for i in words]
camel_case_list = ["".join(x.capitalize() for x in i.lower().split("_")) for i in snake_case_list]
lower_camel_case_list = [i[0].lower() + i[1:] for i in camel_case_list]

print(snake_case_list)
print(camel_case_list)
print(lower_camel_case_list)

for arg in args:

    words = arg.lower().split()

    snake_case = "_".join(words)

    camel_case = "".join(x.capitalize() for x in snake_case.lower().split("_"))

    lower_camel_case = camel_case[0].lower() + camel_case[1:]

    c_contents = f"""
#include <gb/gb.h>
#include <stdio.h>
#include "{snake_case}.h"
#include "../fade.h"

typedef struct _{lower_camel_case} {{
    uint8_t count;
}} {lower_camel_case}Data;

{lower_camel_case}Data {snake_case}_data;

void {snake_case}_init(void *data) {{
    {lower_camel_case}Data *data_ptr = data;
    data_ptr->count = 0;
    fade_in();
}}

uint8_t {snake_case}_iter(void *data) {{
    {lower_camel_case}Data *data_ptr = data;

    return 0;
}}

uint8_t {snake_case}_exit(void *data) {{
    {lower_camel_case}Data *data_ptr = data;
    fade_out();
    return 1;
}}
"""
    h_contents = f"""
#include <gb/gb.h>

typedef struct _{lower_camel_case}Data {lower_camel_case}Data;

extern {lower_camel_case}Data {snake_case}_data;

void {snake_case}_init(void *data);
uint8_t {snake_case}_iter(void *data);
uint8_t {snake_case}_exit(void *data);
"""
 
    with open(file = f"{snake_case}.c", mode = "w") as f:
        f.write(c_contents)
        print(f"created {snake_case}.c")

    with open(file = f"{snake_case}.h", mode = "w") as f:
        f.write(h_contents)
        print(f"created {snake_case}.h")

game_state_c = f"""
#include <gb/gb.h>
#include "game_states.h"
#include "game_states/splash.h"
#include "game_states/main_menu.h"

state"""
# + f"{["\n\t" + i + "," for i in snake_case_list]}"
# + "\b;\n\n"
+ f"{"state *init_(void)"}"
    # {[s + ",\n\t" for s in snake_case_list]}\b\;

# state *init_splashState(void) {
#     # splashState.step = 0;
#     # splashState.init = 
# }


with open(file = "game_states.c", mode = "w") as f:
    f.write(c_contents)
    print("created game_states.c")

with open(file = "game_states.h", mode = "w") as f:
    f.write(h_contents)
    print("created game_states.h")
