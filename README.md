# Ottolay
*Otto bots, dance!*

[Türkçe OKUBENİ için tıklayınız](BENIOKU.md)

Ottolay is short version of `Otto Halay` words. 

## Requirements
Software
* Arduino

Libraries
* OttoDIYLib
* IRremote

### Remote Button Codes
After update from version 2 to 3, `IRremte` library had big changes. Before, library prints the button codes in MSB order; but now it displays in LSB order. So we have two chances:
1. Reverse the bits and use old hardcoded values
2. Use new MSB ordered values

| Button | Old Hex Code | Old Dec Code | New Hex Code | New Dec Code |
|--------|--------------|--------------|--------------|--------------|
| 1      |   0xFFA25D   |   16753245   | 0xBA45FF00   | 3125149440   |
| 2      |   0xFF629D   |   16736925   | 0xB946FF00   | 3108437760   |
| 3      |   0xFFE21D   |   16769565   | 0xB847FF00   | 3091726080   |
| 4      |   0xFF22DD   |   16720605   | 0xBB44FF00   | 3141861120   |
| 5      |   0xFF02FD   |   16712445   | 0xBF40FF00   | 3208707840   |
| 6      |   0xFFC23D   |   16761405   | 0xBC43FF00   | 3158572800   |
| 7      |   0xFFE01F   |   16769055   | 0xF807FF00   | 4161273600   |
| 8      |   0xFFA857   |   16754775   | 0xEA15FF00   | 3927310080   |
| 9      |   0xFF906F   |   16748655   | 0xF609FF00   | 4127850240   |
| 0      |   0xFF9867   |   16750695   | 0xE619FF00   | 3860463360   |
| *      |   0xFF6897   |   16738455   | 0xE916FF00   | 3910598400   |
| #      |   0xFFB04F   |   16756815   | 0xF20DFF00   | 4061003520   |
| OK     |   0xFF38C7   |   16726215   | 0xE31CFF00   | 3810328320   |
| UP     |   0xFF18E7   |   16718055   | 0xE718FF00   | 3877175040   |
| DOWN   |   0xFF4AB5   |   16730805   | 0xAD52FF00   | 2907897600   |
| LEFT   |   0xFF10EF   |   16716015   | 0xF708FF00   | 4144561920   |
| RIGHT  |   0xFF5AA5   |   16734885   | 0xA55AFF00   | 2774204160   |

```
   ------------------
 /                    \
|  CH-    CH     CH+   |
| FFA25D FF629D FFE21D |
|                      |
|  |<<     >>|   |>||  |
| FF22DD FF02FD FFC23D |
|                      |
|   -       +     EQ   |
| FFE01F FFA857 FF906F |
|                      |
|   0      100+  200+  |
| FF6897 FF9867 FFB04F |
|                      |
|   1       2     3    |
| FF30CF FF18E7 FF7A85 |
|                      |
|   4       5     6    |
| FF10EF FF38C7 FF5AA5 |
|                      |
|   7       8     9    |
| FF42BD FF4AB5 FF52AD |
|                      |
|         Car          |
|         mp3          |
 \                    /
   ------------------

   ------------------
 /                    \
|   1       2     3    |
| FFA25D FF629D FFE21D |
|                      |
|   4       5     6    |
| FF22DD FF02FD FFC23D |
|                      |
|   7       8     9    |
| FFE01F FFA857 FF906F |
|                      |
|   *       0     #    |
| FF6897 FF9867 FFB04F |
|                      |
|          UP          |
|        FF18E7        |
|                      |
|   <-     OK     ->   |
| FF10EF FF38C7 FF5AA5 |
|                      |
|         DOWN         |
|        FF4AB5        |
|                      |
|   BLACK BACKGROUND   |
|    REMOTE COMMAND    |
 \                    /
   ------------------
```