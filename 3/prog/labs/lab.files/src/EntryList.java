import java.io.*;
import java.io.IOException;
import java.util.Collection;
import java.util.Vector;
import java.util.function.Consumer;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.stream.Collectors;

public class EntryList extends Vector<Entry> {

    public EntryList() {};

    public void save(OutputStream fos) throws IOException {
        ObjectOutputStream oos = new ObjectOutputStream(fos);
        oos.writeObject(this);
        oos.close();
    }

    public void load(InputStream fis) throws IOException, ClassNotFoundException {
        ObjectInputStream ois = new ObjectInputStream(fis);
        this.addAll((EntryList) ois.readObject());
    }

    public String toString(){
        String out = "Total count:" + this.elementCount + "\n";
        for (Entry entry : this) {
            out += entry.toString() + "\n";
        }
        return out;
    }

    public void fromStream(){

    }

    public void toStream(){

    }

    public void toStream(){

    }

    public void fromStream(){

    }

    public static void generateDefaultData() throws IOException {
        EntryList temp = new EntryList();
        temp.add(new Entry(2733, 176, 8000000, LocalDate.of(2013, 11, 13), "���� \"������ ����������\"", "������������� ����������� ������"));
        temp.add(new Entry(2788, 176, -120128, LocalDate.of(2013, 11, 27), "���� \"������ ����������\"", "������� �������������� �����"));
        temp.add(new Entry(6677, 232, 12660000, LocalDate.of(2013, 8, 16), "�������� ������-������������ �����", "�� ���������� ��� �� �������� "));
        temp.add(new Entry(6678, 232, 19000000, LocalDate.of(2013, 5, 9), "�������� ������-������������ �����", "����� �� ���������� ���"));
        temp.add(new Entry(237, 155, 4572000, LocalDate.of(2014, 11, 1), "��� �������� �����", "���������� ��������� �� �������� ���������"));
        temp.add(new Entry(2111, 155, 89000000, LocalDate.of(2013, 12, 5), "�� \"����������\"","���������� ���������������� �������������� ������"));
        temp.add(new Entry(8189, 155, 4572000, LocalDate.of(2013, 12, 2), "�� ������������", "���������� ��������� ������ ��������� ������"));
        FileOutputStream fos = new FileOutputStream("in.bin");w
        temp.save(fos);
        fos.close();
    }

}
