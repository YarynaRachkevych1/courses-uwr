# frozen_string_literal: true

# def run
#   puts "Zaraz sie zacznie\n"
#   yield
#   yield
#   yield
#   puts "Juz sie skonczyło\n"
# end
#
# run { print " dwa dodac dwa jest \n", 2 + 2 }

# def dodawanie
#   yield 2,2
#   yield 3,4
# end
# # dodawanie { |x, y| puts x + y }
#
# def foo(x, y, &block)
#   print x + y
#   yield
# end
# foo(2, 3) { puts "\nA kuku" }
#
# def foo2(x, y, &blok)
#   yield x, y
# end
# foo2(2, 3) { |a, b| puts a + b }

blok = lambda { puts 2+2 }
blok.call

def powitanie(lang)
  lambda { |kto| lang + " " + kto }
end
ang = powitanie("Hello")
puts ang.call("Mr Bond")

pol = powitanie("Witaj")
puts pol.call("´swiecie")


# def pudelko
#   zawartosc = nil
#   wez = lambda { zawartosc }
#   wloz = lambda { |n| zawartosc = n }
#   return wez, wloz
# end
# odczyt, zapis = pudelko
# puts odczyt.call
# zapis.call(2)
# puts odczyt.call

def bar(block, arg)
  puts block.call(arg)
end
bar(lambda { |n| n*n*n }, 10)
