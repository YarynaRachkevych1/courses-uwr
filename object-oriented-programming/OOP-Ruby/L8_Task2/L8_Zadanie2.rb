class Dlugosc
  def initialize(dlugosc)
    @m = dlugosc
  end
  def m
    @m
  end

  def inm
    @m / 1852
  end
  def inm=(m)
    @imn = m / 1852
  end

  def mwr
    @m / 6700
  end
  def mwr=(m)
    @mwr = m / 6700
  end

  def mm
    @m * 1000
  end
  def mm=(m)
    @mm = @m * 1000
  end

  def km
    @m / 1000
  end
  def km=(m)
    @km = m / 1000
  end
end

class Czas
  def initialize(czas)
    @s = czas
  end
  def s
    @s
  end

  def min
    @s / 60
  end
  def min=(s)
    @min = s / 60
  end

  def h
    @s / 360
  end
  def h=(s)
    @h = s / 360
  end
end

class Predkosc
  def initialize(dlugosc, czas)
    @m = dlugosc
    @s = czas
    @pr = dlugosc.m/czas.s
  end
  def c_pr
    @pr = @m.m / @s.s
  end
  def pr
    @pr
  end

  def km_h
    @m.km / @s.h
  end
  def km_h=(pr)
    @km_h = pr * 3.6
  end

  def mwr_min
    @m.mwr / @s.min
  end
  def mwr_min=(pr)
    @mwr_min = pr * 60 / 6700
  end

  def km_s
    @m.km / @s
  end

  def mm_h
    @m.mm / @s.h
  end
end

class Przyspieszenie
  def initialize(ms1, ms2, czas)
    @pr1 = ms1.pr
    @pr2 = ms2.pr
    @s = czas.s
    @przyspieszenie = (ms2.pr - ms1.pr) / czas.s
  end
  def przyspieszenie
    @przyspieszenie
  end

  def km_s2
    (@pr2.km_s - @pr1.km_s) / @czas
  end
  def km_s2=(przyspieszenie)
    @km_s2 = przyspieszenie * 0.001 * 3.6
  end

  def mm_h2
    (@pr2.mm_h - pr1.mm_h) / @czas.h
  end
  def mm_h2=(przyspieszenie)
    @mm_h2 = przyspieszenie * 1000 * 3600 / 1000 / 1000
  end
end

dl1 = Dlugosc.new(5)
dl2 = Dlugosc.new(40)
czas1 = Czas.new(1000)
czas2 = Czas.new(34000)
pr1 = Predkosc.new(dl1, czas1)
pr1.c_pr
puts pr1.pr
pr2 = Predkosc.new(dl2, czas2)
pr3 = Predkosc.new(dl1, czas2)
pr4 = Predkosc.new(dl2, czas1)
predkosci = [pr1, pr2, pr3, pr4]
puts "Predkosci: "
puts "+-------+-------+--------------+"
puts "| M/s | Km/h    | Mili Wr/min    |"
puts "+-------+-------+--------------+"

predkosci.each do |pr|
  puts sprintf("| %5.1f | %5.2f | %12.3e |", pr.pr, pr.km_h, pr.mwr_min)
end
puts "+-------+-------+--------------+"