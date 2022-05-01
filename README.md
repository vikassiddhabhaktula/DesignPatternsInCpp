# DesignPatternsInCpp
Design Patterns:
-   Single responsibility design code added
-   Open-Closed design:
    -   A design choice to enable scalability but also disable code modification
-   Liskov substitute:
    -   Always make sure the base class reference can always be substituted with a derived class reference.
    -   Doing so shouldn't break anything
    -   TODO: example
-   Interface Segregation:
    -   Make sure the interfaces are segreagated.
    -   And are small and concise
    -   This makes the development & maintenance easy
-   Dependency Inversion:
    -   Make sure high level modules are not dependent on low level modules
        directly
    -   Instead, create interfaces and only expose interfaces to the High level
    -   This way, even an implementation change in LL will not break HL