import java.util.*;

public class Graph {

    private class Person
    {

        String name;
        List<Person> friends;

        public Person(String name) {
            this.name = name;
            this.friends = new ArrayList<>();
        }

        public boolean DFS(Person p1, Person p2, Set<Person> asked) 
        {
            if (asked.contains(p1))
                return false;

            if (p1 == p2)
                return true;

            for (Person friend : p1.friends) {
                if (DFS(friend, p2, asked))
                    return true;
            }
            return false;
        }

        public boolean BFS(Person p1, Person p2) 
        {
            Queue<Person> nextToAsk = new LinkedList<>();
            Set<Person> asked = new HashSet<>();
            nextToAsk.add(p1);
            asked.add(p1);

            while (!nextToAsk.isEmpty()) 
            {
                Person needy = nextToAsk.remove();

                if (needy == p2)
                    return true;

                asked.add(needy);

                for (Person friend : needy.friends) {
                    if (!asked.contains(friend)) {
                        nextToAsk.add(friend);

                    }

                }
            }
            return false;

        }

    }
}
