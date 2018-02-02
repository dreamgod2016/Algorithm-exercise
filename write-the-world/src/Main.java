import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] arg0)
    {
        BigInteger number;
        int sum = 0;

        String[] numToPinYin = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
        String result = "";
        Scanner sc = new Scanner(System.in);
        number = sc.nextBigInteger();

        while(number.compareTo(BigInteger.ZERO) > 0)
        {
            sum = sum + number.remainder(BigInteger.TEN).intValue();
            number = number.divide(BigInteger.TEN);
        }
        while(sum > 0)
        {
            result = new StringBuilder(numToPinYin[sum%10]).append(" ").append(result).toString() ;
            sum /= 10;
//            if(sum != 0)
//                result = result + " ";
        }
        result = result.substring(0,result.length()-1);
        System.out.println(result);
    }
}
