
/*
 * Author  : Hemanatha Bhagavathar
 * License : MIT
*/ 

#include <stdio.h>
int main() {

char *note[12][12] = {
     { "A"  , "A#" , "B"  , "C"  , "C#" , "D"  , "D#" , "E"  , "F"  , "F#" , "G"  , "G#" },
     { "A#" , "B"  , "C"  , "C#" , "D"  , "D#" , "E"  , "F"  , "F#" , "G"  , "G#" , "A"  },
     { "B"  , "C"  , "C#" , "D"  , "D#" , "E"  , "F"  , "F#" , "G"  , "G#" , "A"  , "A#" },
     { "C"  , "C#" , "D"  , "D#" , "E"  , "F"  , "F#" , "G"  , "G#" , "A"  , "A#" , "B"  },
     { "C#" , "D"  , "D#" , "E"  , "F"  , "F#" , "G"  , "G#" , "A"  , "A#" , "B"  , "C"  },
     { "D"  , "D#" , "E"  , "F"  , "F#" , "G"  , "G#" , "A"  , "A#" , "B"  , "C"  , "C#" },
     { "D#" , "E"  , "F"  , "F#" , "G"  , "G#" , "A"  , "A#" , "B"  , "C"  , "C#" , "D"  },
     { "E"  , "F"  , "F#" , "G"  , "G#" , "A"  , "A#" , "B"  , "C"  , "C#" , "D"  , "D#" },
     { "F"  , "F#" , "G"  , "G#" , "A"  , "A#" , "B"  , "C"  , "C#" , "D"  , "D#" , "E"  },
     { "F#" , "G"  , "G#" , "A"  , "A#" , "B"  , "C"  , "C#" , "D"  , "D#" , "E"  , "F"  },
     { "G"  , "G#" , "A"  , "A#" , "B"  , "C"  , "C#" , "D"  , "D#" , "E"  , "F"  , "F#" },
     { "G#" , "A"  , "A#" , "B"  , "C"  , "C#" , "D"  , "D#" , "E"  , "F"  , "F#" , "G"  } 
  } ;

  int i, j, k, x, y;
  char *major_chord[8];
  char *minor_chord[8];

  /*
   *
   * RULE OF THUMB for MAJOR Scale is explained in different ways in music theory/parlance, 
   * though it means the same action to be taken:
   *
   * 1) whole note + whole note + half note + whole note + whole note + whole note + half note
   *
   * 2) major 2nd + major 2nd + minor 2nd + major 2nd + major 2nd + major 2nd + minor 2nd
   *
   * 3) full tone + full tone + semi tone + full tone + full tone + full tone + semi tone
   *
   * 4) skip 2 frets, skip 2 frets, skip 1 fret, skip 2 frets, skip 2 frets, skip 2 frets, skip 1 fret
   *
   *    Play the note before skipping the fret(s)
   *
   */
   
   int major[7]={ 2, 2, 1, 2, 2, 2, 1 };

  /*
   *
   * RULE OF THUMB for MINOR Scale is explained in different ways in music theory/parlance, 
   * though it means the same action to be taken:
   *
   * 1) whole note + half note + whole note + whole note + half note + whole note + whole note
   *
   * 2) major 2nd + minor 2nd + major 2nd + major 2nd + minor 2nd + major 2nd + major 2nd
   *
   * 3) full tone + semi tone + full tone + full tone + semi tone + full tone + full tone
   *
   * 4) skip 2 frets, skip 1 fret, skip 2 frets, skip 2 frets, skip 1 fret, skip 2 frets, skip 2 frets
   *
   *    Play the note before skipping the fret(s)
   *
   */

   int minor[7]={ 2, 1, 2, 2, 1, 2, 2 };

   printf("\nChord progressions for Major and Minor Scales\n");
   printf("---------------------------------------------\n\n");

   printf("Key Signature of Major Scale : { 2, 2, 1, 2, 2, 2, 1 } \n\n");
   printf("Key Signature of Minor Scale : { 2, 1, 2, 2, 1, 2, 2 } \n\n");

   /* Loop to iterate each row in the *note[][] double dimensional array */
   for(i=0; i<12; i++)
   {
	printf("\nDEGREE / POSITION\t:\t%s\t%s\t%s\t%s\t%s\t%s\t%s", "[1]", "[2]", "[3]", "[4]", "[5]", "[6]", "[7]" ); 
	printf("\nMajor scale of %s\t:\t", note[i][0]);

	/* Loop to iterate each element in a row */
	for(j=0; j<12; j++)
	{
		x=0;

		/* Loop to iterate on each row to pick only 7 notes, based on the Rule of Thumb for Major */
		for(k=0; k<7; k++)
		{
			printf("%s\t", note[i][j]) ; 
			major_chord[x++] = note[i][j] ; 
			j = j + major[k] ;
		} 
		
		/* Major Chord in any given Scale: Play notes in position - 1, 3 and 5 */
		printf("\n%s Major chord\t\t:\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t<<-- Play notes together in positions 1, 3 and 5\n", major_chord[0], major_chord[0], "--", major_chord[2], "--", major_chord[4], "--", "--") ; 

		/* Major Power Chord in any given Scale: Play notes in position - 1 and 5 */
		printf("%s Major Power chord\t:\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t<<-- Play notes together in positions 1 and 5\n", major_chord[0], major_chord[0], "--", "--", "--", major_chord[4], "--", "--") ; 

		/* Major 7th Chord in any given Scale: Play notes in position - 1, 3, 5 and 7 */
		printf("%s Major 7th chord\t:\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t<<-- Play notes together in positions 1, 3, 5 and 7\n", major_chord[0], major_chord[0], "--", major_chord[2], "--", major_chord[4], "--", major_chord[6]) ; 

		/* Major Sustained Chord in any given Scale: Play notes in position - 2 and 5 */
		printf("%s Major sust. chord\t:\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t<<-- Play notes together in positions 2 and 5\n", major_chord[0], major_chord[0], major_chord[1], "--", "--", major_chord[4], "--", "--") ; 
	}

	printf("%s\n", "-----------------------------------------------------------------------------------");

	printf("\nDEGREE / POSITION\t:\t%s\t%s\t%s\t%s\t%s\t%s\t%s", "[1]", "[2]", "[3]", "[4]", "[5]", "[6]", "[7]" ); 
	printf("\nMinor scale of %s\t:\t", note[i][0]);

	/* Loop to iterate each element in a row */
	for(j=0; j<12; j++)
	{
		y=0;

		/* Loop to iterate on each row to pick only 7 notes, based on the Rule of Thumb for Minor */ 
		for(k=0; k<7; k++)
		{
			printf("%s\t", note[i][j]) ;
			minor_chord[y++] = note[i][j] ; 
			j = j + minor[k] ;
		} 

		/* Minor Chord in any given Scale: Play notes in postion - 1, 3 and 5 */
		printf("\n%s Minor chord\t\t:\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t<<-- Play notes together in positions 1, 3 and 5\n", minor_chord[0], minor_chord[0], "--", minor_chord[2], "--", minor_chord[4], "--", "--") ;

		/* Minor Power Chord in any given Scale: Play notes in postion - 1 and 5 */
		printf("%s Minor Power chord\t:\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t<<-- Play notes together in positions 1 and 5\n", minor_chord[0], minor_chord[0], "--", "--", "--", minor_chord[4], "--", "--") ;

		/* Minor 7th Chord in any given Scale: Play notes in postion - 1, 3, 5 and 7 */
		printf("%s Minor 7th chord\t:\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t<<-- Play notes together in positions 1, 3, 5 and 7\n", minor_chord[0], minor_chord[0], "--", minor_chord[2], "--", minor_chord[4], "--", minor_chord[6]) ;

		/* Minor Sustained Chord in any given Scale: Play notes in postion - 2 and 5 */
		printf("%s Minor sust. chord\t:\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t<<-- Play notes together in positions 2 and 5\n", minor_chord[0], minor_chord[0], minor_chord[1], "--", "--", minor_chord[4], "--", "--") ;
	}
	printf("%s\n", "-----------------------------------------------------------------------------------");
   }

} /* End of main */

