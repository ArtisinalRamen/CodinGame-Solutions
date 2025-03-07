using System;

class Player {
    static void Main(string[] args) {
        while (true) {
            int largestMountain = 0;
            int index = 0;
            for (int i = 0; i < 8; i++) {
                int mountainH = int.Parse(Console.ReadLine()); // represents the height of one mountain.
                if (mountainH > largestMountain) {
                    largestMountain = mountainH;
                    index = i;
                }
            }
            Console.WriteLine(index); 
        }
    }
}