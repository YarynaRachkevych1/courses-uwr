# Yaryna Rachkevych
# PO. Lista 10, Zadanie 1

class Collection
  def initialize(block)
    @collection = block
  end

  def swap(i, j)
    @collection[i], @collection[j] = @collection[j], @collection[i]
  end

  def len
    @collection.length
  end

  def get(i)
    @collection[i]
  end

  def change(i, x)
    @collection[i] = x
  end

  def print_collection
    print "("
    for i in (0..len-1) do
      print get(i).to_s
      print ", " if i < len - 1
    end
    print ")\n"
  end
end

class Sorter
  # Sotowanie bąbelkowe
  def sort1(collection)
    n = collection.len
    for i in 0..n do
      for j in 0..n-i-2 do
        collection.swap(j, j+1) if collection.get(j) > collection.get(j+1)
      end
    end
  end

  # Sortowanie przez wstawianie
  def sort2(collection)
    n = collection.len - 1
    for i in 1..n do
      key = collection.get(i)
      j = i -1
      while j >= 0 && key < collection.get(j) do
        collection.swap(j+1, j)
        j -= 1
      end
      collection.change(j + 1, key)
    end
  end
end


collection1 = Collection.new([4, 2, 8, 5, 1, 7])
collection2 = Collection.new(["aa", "b", "c", "yy", "z"])

print "Kolekcja 1: "
collection1.print_collection
print "Posrowana kolekcja, metoda sort1: "
sort = Sorter.new
sort.sort1(collection1)
collection1.print_collection
puts

print "Kolekcja 2: "
collection2.print_collection
print "Posrowana kolekcja, metoda sort2: "
sort.sort2(collection2)
collection2.print_collection

# sort2 jest szybsze od sort1