#  Physics-based Fluid Mechanics Simulator

A C-based, menu-driven fluid mechanics simulator designed to tackle fluid problems. The user picks a situation from a menu and enters the required values, and the program calculates the physical quantities involved, gives a short verdict where relevant (for example, whether an object floats or sinks), and draws a simple diagram of the situation.

##  Key calculations

* **Pressure at a depth:** (P) Gauge and absolute pressure at a given depth in a fluid.
* **Buoyant force:** (F_b) Upward force on an object in a fluid, with a floats / sinks / neutral verdict.
* **Continuity equation:** (v2, Q) Speed of the fluid in the second section of a pipe and the volume flow rate.
* **Bernoulli's equation:** (P2) Pressure at the second point of a streamline.
* **Exit speed from a tank:** (v, t, x) Exit speed of water from a hole, time of fall and horizontal range of the jet.
* **Pressure comparison:** (P_A, P_B) Gauge pressure at two points, with a comparison of which is greater.

## Description

heavily inspired, once again ,from the physics lecture straight out of my high school classroom, i have built this program as my next step towards blending my passion for computer science and physics concepts. this project is an accumulation of 6 different models that i have defined each separately as 6 different functions that the main function calls upon according to the users input; this feature uses a switch case to call upon the function called for. i have also used a do while loop so the loop runs even after the user has calculated desired results from one of the six models. i have also used a if /else for verifying the users input for it should be a integer >1 and <8 if the user enters a alphabet , this statement makes sure the program doesn't loop/crash. next, as discussed earlier, unique functions have been defined for each of the 6 models that the user may choose from using a switch case, where the main function then calls for that function and the inputs are taken; the results are displayed accordingly. there is also use of hard coded diagrams for most of the models to better understand the concept that i first drew by hand physically , then hard coded onto the program. for reference the six models (with brief details on them)are :
| Option | Diagram | What the diagram shows |
|---|---|---|
| 1. Pressure at a depth | Yes | Tank with the water surface, P0 at the top, a point at depth h, and the total pressure P |
| 2. Buoyant force | Yes | An object at the surface with F_b pointing up and W pointing down |
| 3. Continuity equation | Yes | A wide pipe narrowing into a smaller one, with A1, v1 and A2, v2 labelled |
| 4. Bernoulli's equation | Yes | Two points on a streamline with P, v and h labelled at each |
| 5. Exit speed from a tank | Yes | Tank with depth h, the hole, the curved jet and the range x |
| 6. Pressure comparison | No | Only text output: the two pressures and which is greater |

Additionally, all diagrams are simple ASCII art printed with `printf`. They are not to scale, and only the numbers inside them change with the input. 
As i am going to be uploading the code for the same very soon, i will become more fluent with git push and uploading my code, making me more experienced with git uploads. personally, i also learned about the deleted repositories and their segment , as i earlier deleted this repository due to there being some errors, however this taught me that deleting a repo on GitHub removes it from my account, so I now double-check before deleting anything and keep a copy of my code locally. also i learnt more about supporting functions (used in my code as the six physics models)that the main function can call upon to get the desired theoretical results. i also became familiar with the math.h library, and learnt abt the fabs() which gives us the absolute value. for example, Option 2, buoyant_force(): fabs(rho_obj - rho_f) < 0.01 checks whether the object’s density equals the fluid’s density (neutrally buoyant). i also became more familiar with defining for example the atmospheric pressure and the acceleration due to gravity , plus   working with int and float data types and specifiers.
for my next GitHub project, i will be slightly pivoting towards a math project that is matrix operations; for that will teach me strings and arrays and make me more advanced in c coding.

## Formulas used

* Pressure at a depth: `P = rho * g * h` (gauge), `P = P0 + rho * g * h` (absolute)
* Buoyant force: `F_b = rho_fluid * V * g`
* Weight and object density: `W = m * g`, `rho_obj = m / V`
* Fraction submerged (floating object): `rho_obj / rho_fluid`
* Apparent weight (sinking object): `W - F_b`
* Continuity equation: `A1 * v1 = A2 * v2`, so `v2 = (A1 * v1) / A2`
* Volume flow rate: `Q = A1 * v1`
* Bernoulli's equation: `P1 + (1/2) * rho * v1^2 + rho * g * h1 = P2 + (1/2) * rho * v2^2 + rho * g * h2`
* Pressure at the second point: `P2 = P1 + (1/2) * rho * (v1^2 - v2^2) + rho * g * (h1 - h2)`
* Torricelli's law (exit speed): `v = sqrt(2 * g * h)`
* Time of fall of the jet: `t = sqrt(2 * y / g)`
* Horizontal range of the jet: `x = v * t`
* Pressure comparison: `P_A = rho1 * g * h1`, `P_B = rho2 * g * h2`

