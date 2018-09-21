
package rw;
import java.util.concurrent.Semaphore;
public class RW{
static int rc=0;
static Semaphore s=new Semaphore(1);
static Semaphore wrt=new Semaphore(1);
static class Reader implements Runnable
{
    public void run()
    { try{
        s.acquire();
        rc=rc+1;
        if(rc==1)
        wrt.acquire();
        s.release();
        System.out.println(Thread.currentThread().getName()+" is reading");
        Thread.sleep(500);
        s.acquire();
        rc=rc-1;
        if(rc==0)
        wrt.release();
        s.release();
    }
    catch(Exception E){}
}
}
static class Writer implements Runnable
{
    public void run()
    { try{
        wrt.acquire();
        System.out.println("writer is writing");
        Thread.sleep(1000);
        wrt.release();
    }
    catch(Exception E){}
}}
     public static void main(String []args){
         Reader r= new Reader();
         Writer w= new Writer();
         Thread t1=new Thread(r);
         t1.setName("reader 1");
         t1.start();
         Thread t2=new Thread(r);
         t2.setName("reader 2");
         t2.start();
         Thread t3=new Thread(w);
    t3.start();
     }
}
