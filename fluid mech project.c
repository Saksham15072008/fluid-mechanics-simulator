#include <stdio.h>
#include <math.h>

#define G 9.8
#define P_ATM 101325.0
void pressure_at_depth()
{
    float rho, h;

    printf("\n--- 1. PRESSURE AT A DEPTH ---\n");
    printf("Enter fluid density rho (kg/m^3, water = 1000): ");
    scanf("%f", &rho);
    printf("Enter depth h (m): ");
    scanf("%f", &h);

    if (rho <= 0 || h < 0)
    {
        printf("Please enter rho > 0 and h >= 0\n");
        return;
    }

    float gauge = rho * G * h;
    float absolute = P_ATM + gauge;

    printf("\nGauge pressure    = %.2f Pa\n", gauge);
    printf("Absolute pressure = %.2f Pa  (%.3f atm)\n\n", absolute, absolute / P_ATM);


    printf("      Atmosphere  P0 = 101325 Pa\n");
    printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  <- surface\n");
    printf(" |                                     |\n");
    printf(" |                                     |\n");
    printf(" |                  *  Point           |   h = %.2f m\n", h);
    printf(" |                                     |\n");
    printf(" |_____________________________________|\n");
    printf("   P = P0 + rho*g*h = %.2f Pa\n", absolute);
}

void buoyant_force()
{
    float rho_f, V, m;

    printf("\n--- 2. BUOYANT FORCE ---\n");
    printf("Enter fluid density rho (kg/m^3): ");
    scanf("%f", &rho_f);
    printf("Enter volume of object V (m^3): ");
    scanf("%f", &V);
    printf("Enter mass of object m (kg): ");
    scanf("%f", &m);

    if (rho_f <= 0 || V <= 0 || m <= 0)
    {
        printf("Please enter all values > 0\n");
        return;
    }

    float Fb = rho_f * V * G;
    float W = m * G;
    float rho_obj = m / V;

    printf("\nObject density            = %.2f kg/m^3\n", rho_obj);
    printf("Weight of object          = %.2f N\n", W);
    printf("Buoyant force (submerged) = %.2f N\n", Fb);

    if (fabs(rho_obj - rho_f) < 0.01)
    {
        printf("Result: object is neutrally buoyant (stays wherever it is placed)\n");
    }
    else if (rho_obj < rho_f)
    {
        printf("Result: object FLOATS\n");
        printf("Actual buoyant force      = %.2f N (equals its weight)\n", W);
        printf("Fraction submerged        = %.2f %%\n", rho_obj / rho_f * 100);
    }
    else
    {
        printf("Result: object SINKS\n");
        printf("Apparent weight           = %.2f N\n", W - Fb);
    }


    printf("\n        Fb (up)\n");
    printf("          ^\n");
    printf("          |\n");
    printf(" ~~~~~~~~~|~~~~~~~~~~~~~~  <- surface\n");
    printf("      +---+---+\n");
    printf("      | object|\n");
    printf("      +---+---+\n");
    printf("          |\n");
    printf("          v\n");
    printf("        W (down)\n");
}


void continuity_equation()
{
    float A1, v1, A2;

    printf("\n--- 3. CONTINUITY EQUATION (A1 v1 = A2 v2) ---\n");
    printf("Enter area A1 (m^2): ");
    scanf("%f", &A1);
    printf("Enter speed v1 (m/s): ");
    scanf("%f", &v1);
    printf("Enter area A2 (m^2): ");
    scanf("%f", &A2);

    if (A1 <= 0 || v1 <= 0 || A2 <= 0)
    {
        printf("Please enter all values > 0\n");
        return;
    }

    float v2 = A1 * v1 / A2;
    float Q = A1 * v1;

    printf("\nSpeed v2          = %.2f m/s\n", v2);
    printf("Volume flow rate  = %.4f m^3/s\n", Q);

    if (A2 < A1)
        printf("Pipe narrows, so the fluid speeds up.\n\n");
    else if (A2 > A1)
        printf("Pipe widens, so the fluid slows down.\n\n");
    else
        printf("Same area, so the speed does not change.\n\n");

    printf(" ____________________\n");
    printf("                     \\______________\n");
    printf("  A1 = %-6.3f m^2      A2 = %-6.3f m^2\n", A1, A2);
    printf("  v1 = %-6.2f m/s  -->  v2 = %-6.2f m/s\n", v1, v2);
    printf(" ____________________ /______________\n");
}

void bernoulli_equation()
{
    float rho, P1, v1, h1, v2, h2;

    printf("\n--- 4. BERNOULLI'S EQUATION ---\n");
    printf("(P1 + 1/2 rho v1^2 + rho g h1 = P2 + 1/2 rho v2^2 + rho g h2)\n");
    printf("Enter fluid density rho (kg/m^3): ");
    scanf("%f", &rho);
    printf("Enter pressure P1 (Pa): ");
    scanf("%f", &P1);
    printf("Enter speed v1 (m/s): ");
    scanf("%f", &v1);
    printf("Enter height h1 (m): ");
    scanf("%f", &h1);
    printf("Enter speed v2 (m/s): ");
    scanf("%f", &v2);
    printf("Enter height h2 (m): ");
    scanf("%f", &h2);

    if (rho <= 0 || v1 < 0 || v2 < 0)
    {
        printf("Please enter rho > 0 and speeds >= 0\n");
        return;
    }

    float speed_term = 0.5 * rho * (v1 * v1 - v2 * v2);
    float height_term = rho * G * (h1 - h2);
    float P2 = P1 + speed_term + height_term;

    printf("\nPressure change due to speed  = %.2f Pa\n", speed_term);
    printf("Pressure change due to height = %.2f Pa\n", height_term);
    printf("Pressure P2                   = %.2f Pa\n", P2);
    printf("(P2 is gauge or absolute, the same type as the P1 you entered)\n\n");


    printf("   Point 2: P2, v2, h2\n");
    printf("        o------->\n");
    printf("       /\n");
    printf("      /   streamline\n");
    printf("     /\n");
    printf("    o------->\n");
    printf("   Point 1: P1, v1, h1\n");
}


void exit_speed_tank()
{
    float h, y;

    printf("\n--- 5. EXIT SPEED FROM A TANK (TORRICELLI) ---\n");
    printf("Enter depth of hole below water surface h (m): ");
    scanf("%f", &h);
    printf("Enter height of hole above the ground y (m): ");
    scanf("%f", &y);

    if (h <= 0 || y <= 0)
    {
        printf("Please enter h > 0 and y > 0\n");
        return;
    }

    float v = sqrt(2 * G * h);
    float t = sqrt(2 * y / G);
    float x = v * t;

    printf("\nExit speed       = %.2f m/s\n", v);
    printf("Time of fall     = %.2f seconds\n", t);
    printf("Horizontal range = %.2f meters\n\n", x);


    printf(" |~~~~~~~~~~~~~~~~~~~|  <- water surface\n");
    printf(" |                   |\n");
    printf(" |                   |   h = %.2f m\n", h);
    printf(" |                   |\n");
    printf(" |                   o----.\n");
    printf(" |                   |     '--.\n");
    printf(" |                   |   y       '--.\n");
    printf(" |___________________|______________'--> \n");
    printf("                      <-- Range x = %.2f m -->\n", x);
}


void pressure_comparison()
{
    float rho1, h1, rho2, h2;

    printf("\n--- 6. PRESSURE COMPARISON ---\n");
    printf("Point A:\n");
    printf("  Enter fluid density rho1 (kg/m^3): ");
    scanf("%f", &rho1);
    printf("  Enter depth h1 (m): ");
    scanf("%f", &h1);
    printf("Point B:\n");
    printf("  Enter fluid density rho2 (kg/m^3): ");
    scanf("%f", &rho2);
    printf("  Enter depth h2 (m): ");
    scanf("%f", &h2);

    if (rho1 <= 0 || rho2 <= 0 || h1 < 0 || h2 < 0)
    {
        printf("Please enter rho > 0 and depth >= 0\n");
        return;
    }

    float PA = rho1 * G * h1;
    float PB = rho2 * G * h2;

    printf("\nGauge pressure at A = %.2f Pa\n", PA);
    printf("Gauge pressure at B = %.2f Pa\n", PB);

    if (fabs(PA - PB) < 0.01)
        printf("Result: pressure at A and B is EQUAL\n");
    else if (PA > PB)
        printf("Result: pressure at A is greater (A/B = %.2f)\n", PA / PB);
    else
        printf("Result: pressure at B is greater (B/A = %.2f)\n", PB / PA);

    if (fabs(rho1 - rho2) < 0.01)
        printf("Same fluid: pressure depends only on depth, not on container shape.\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n\t\t ========== FLUID MECHANICS SIMULATOR ========== \n \n");
        printf("1. Pressure at a depth\n");
        printf("2. Buoyant force\n");
        printf("3. Continuity equation\n");
        printf("4. Bernoulli's equation\n");
        printf("5. Exit speed from a tank\n");
        printf("6. Pressure comparison\n");
        printf("7. Exit\n \n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n');
            choice = 0;
        }

        switch (choice)
        {
            case 1: pressure_at_depth();   break;
            case 2: buoyant_force();       break;
            case 3: continuity_equation(); break;
            case 4: bernoulli_equation();  break;
            case 5: exit_speed_tank();     break;
            case 6: pressure_comparison(); break;
            case 7: printf("\nThank you for using the simulator!\n"); break;
            default: printf("\nInvalid choice, please enter 1 to 7\n");
        }
    } while (choice != 7);

    return 0;
}
