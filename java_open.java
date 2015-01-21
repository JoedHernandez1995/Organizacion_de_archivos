import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class File_Open {
    public static void main(String[] args) {
        
        try{
            String linea;
            FileReader archivo = new FileReader("/Users/joedhernandez/Desktop/file.txt");
            BufferedReader buffer = new BufferedReader(archivo);
            while((linea = buffer.readLine())!= null){
                System.out.println(linea);
            }
            buffer.close();
        }catch(IOException e){
            e.printStackTrace();
            System.err.println("FILE NOT FOUND");
        }
    }
}
