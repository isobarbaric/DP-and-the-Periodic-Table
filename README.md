# The Periodic Table : Dynamic Programming
> “You don’t have to memorize electron configurations anymore, just run this here program once and off you go!”

The aim of this project was to emulate the filling of electrons in an atom’s shells as per the Aufbau principle but through the approach of dynamic programming, not a direct simulation. C++’s OOPS capabilities were utilized to create a representation of the quantum model of the atom by individually creating classes of different parts of the bit. 

Furthermore, from a more computer science perspective, the idea for this project was initially envisioned from the glaring similarity seen between dynamic programming and the notion of shorthand notation in atomic chemistry. Essentially, one of the guiding aims of this project was to apply the fundamental principles of dynamic programming and use that to contribute to building a periodic table from scratch with limited information, to begin with. Electron configurations were generated for each element using the idea of shorthand notation and the general paradigm of dynamic programming. Individual states are each element (naturally), and the transitions are made using the previous and closest noble gas. Note that the base cases are hydrogen and helium. The electron configuration of the original noble gas is first copied. Then, using the information contained in the complete electron configuration of whatever this noble gas happens to be, the remainder of the electrons in the current element can be filled into the rest of the shells per the Aufbau principle. To assist in the construction of this model of the periodic table, [data](#Attributions-and-Credit) was imported from external sources in JSON format ([ultimately processed in C++](#Attributions-and-Credit)) and then individually catered for the specific needs of the project using a simple python script to strip the JSON data of fields that were not of use for the current project. 

Note that this project does not account for exceptions to the Aufbau principle and does not provide an inner look at orbitals (Hund’s rule). All deductions are made exclusively based on the Aufbau principle only, and any exceptions to the Aufbau principle have not been accounted for. Unfortunately, while preserving the intended paradigm of the project, this design choice discounts the accuracy of some of the electron configurations rendered. Thus, as a disclaimer, 
all users are to use this application at their own risk. The author is not liable for any complaints of inaccurate data. 

# Attributions and Credit 
Periodic Table JSON data: [Periodic-Table-JSON](https://github.com/Bowserinator/Periodic-Table-JSON)

library to parse through JSON in C++: [Jsoncpp](https://github.com/open-source-parsers/jsoncpp)
