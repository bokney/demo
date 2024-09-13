
import sys

"""
NAMING CONVENTIONS:
    - snake_case
        - regular values and functions
        - class/structure instances
    - lowerCamelCase
        - class/structure definitions
    - UpperCamelCase
        - not used?
"""

if len(sys.argv) <= 1:
    print("Expected 1 or more arguments")
    exit()

states_individual_dependencies = []
states_assign = []

args = sys.argv[1:]
for i, arg in enumerate(args):

    state_name_word_list = arg.lower().split()

    snake_case = "_".join(state_name_word_list)

    upper_camel_case = "".join(w.capitalize() for w in state_name_word_list)

    lower_camel_case = upper_camel_case[0].lower() + upper_camel_case[1:]

    print(f"word list: {state_name_word_list}")
    print(f"snake case: {snake_case}")
    print(f"lower camel case: {lower_camel_case}")
    print(f"upper camel case: {upper_camel_case}")

    # # # #

    states_individual_dependencies.append(f"#include \"{snake_case}.h\"\n")
    states_assign.append(f"""
void assign_{snake_case}(state *state) {{
    state->init = &{snake_case}_init;
    state->iter = &{snake_case}_iter;
    state->exit = &{snake_case}_exit;
}}
""")

    # # # #

    state_source_dependencies = f"""
#include <gb/gb.h>
#include "{snake_case}.h"
"""

    data_struct_definition = f"""
typedef struct _{lower_camel_case} {{
    uint8_t count;
}} {lower_camel_case}Data;
"""

    data_struct_declaration = f"""
{lower_camel_case}Data {snake_case}_data;
"""

    state_init = f"""
void {snake_case}_init(void) {{
    {snake_case}_data.count = 0;
}}
"""

    state_iter = f"""
uint8_t {snake_case}_iter(void) {{
    {snake_case}_data.count += 1;
    return 0;
}}
"""

    state_exit = f"""
uint8_t {snake_case}_exit(void) {{
    return 0;
}}
"""

    print(
        state_source_dependencies +
        data_struct_definition +
        data_struct_declaration +
        state_init +
        state_iter +
        state_exit
        )

states_common_dependencies = f"""
#include <gb/gb.h>
#include "flow_states.h"
"""

print(
    states_common_dependencies +
    "".join(states_individual_dependencies) +
    "".join(states_assign)
    )