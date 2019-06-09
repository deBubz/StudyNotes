public class NumberToWords {
    public static void main(String[] args) {
        String[] teens = {"","one", "two", "three","four","five", "six", "seven", "eight", "nine", "ten", "eleven","twelve", "thirteen", "fourteen" , "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
        String[] tens = {"","","twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
        System.out.print("Number: ");
        int input = In.nextInt();
        
        while (input != -1) {
            int unit = input % 10;
            int ten = input/10%10;
            int hund = input /100;
            
            String output = "";
            String shund, sten, sunit = "";
            
            if(input == 0){
                output = "zero";
            }
            else if(input <= 19){
                output = teens[input];
            }
            else if(input <= 99){
                output = tens[ten]+" "+teens[unit];
            }
             else if(input <= 999){

                //System.out.print(teens[input/100] + " hundred and " + System.out.println(tens[ten]+teens[unit]));
                if(ten == 0 && unit ==0){
                    output = teens[hund]+ " hundred";
                }
                else if(ten == 1){
                    output = teens[hund]+ " hundred and " + teens[input%100];
                }
                else if (ten == 0){
                    output = teens[hund]+ " hundred and " + teens[unit];
                }
                else if(unit == 0) output = teens[hund]+ " hundred and " + tens[ten];
                else output = teens[hund]+ " hundred and " + tens[ten]+" "+teens[unit];
                //else threedigits = teens[hund]+ " hundred and " + tens[ten]+teens[unit];
                
                
                
            }
            
            System.out.println(output);
            System.out.print("Number: ");
            input = In.nextInt();
        }
    }
}