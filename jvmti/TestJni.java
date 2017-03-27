import java.io.*;

public class TestJni {

  private static native void printMsg();

  public static void main(String args[]) {
    printMsg();
    System.out.println("Inside JAVA program main method ...");
  }

}
