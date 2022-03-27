# DP-and-the-Periodic-Table 

**more details about this project can be found [here](https://www.mediafire.com/file/dhg0oubz2wfsis8/DP-and-the-Periodic-Table.pdf/file)**


### Motivation and Description for the Project

I first conceived the idea for this project in the midst of chemistry
class seemingly out of random - we were going our unit on the periodic
table and we discussed shorthand notation. Shorthand notation is
basically the crux of why the idea behind this project works. In case
the reader is not familiar with shorthand notation, let me give a quick
explanation of what shorthand notation (or atleast try to).  

Shorthand notation is a way to write the electronic configuration of an
element using the previous noble gas as a starting point and then
essentially just adding in the extra electrons for the current element.
I hope that’s a satisfactory explanation but just in case it’s not
clear, here’s [a video][] to clear things up a bit.  

Its use in chemistry is mostly one of simplification - it helps express
the electronic configuration of an element with relative ease compared
to writing out the entire electronic configuration. For the purposes of
this project, however, shorthand notation is basically the premise which
makes dynamic programming relevant in this context. Given that the
electronic configuration for an element can be determined using the
previous noble gas, essentially with the electronic configuration for
each element being a , the noble gas configurations all serve as ways
for [^1] - and are both terms associated with dynamic programming.  

Using this as well as the to dictate the order in which shells were
filled, I was able to successfully determine the electronic
configurations for all elements using their respective previous noble
gas as part of my transitions[^2].

[^1]: This does not account for all anomalies that exist - there are
    certainly *many* elemental exceptions.

[^2]: Note that this does not account for elements that are exceptions
    to the Aufbau principle.

  [a video]: https://www.youtube.com/watch?v=5mP0z1MAdCk
 
### Try It Out Yourself!

After cloning the repository, you must first enter the folder containing
the cloned repository. If an IDE is being used, this can be done through
the IDE itself, however, if not, then the following commands can be used
to run the program through the terminal:  
for Linux and Mac:
```
cd Dynamic-Programming-and-the-Periodic-Table
pip3 install -r requirements.txt
python3 main.py    
```
for Windows:
```
  cd Dynamic-Programming-and-the-Periodic-Table
  pip install -r requirements.txt
  python main.py
```
The program should then execute! Cheers!
