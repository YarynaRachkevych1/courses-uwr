from sqlalchemy import create_engine, ForeignKey, Column, String, Integer
from sqlalchemy.orm import relationship, validates
from sqlalchemy.ext.declarative import declarative_base

Base = declarative_base()

class Series(Base):
    __tablename__ = "series"

    name = Column("name", String, primary_key=True)
    release_year = Column("release_year", Integer)
    producer = relationship("Producer", back_populates="series")
    episodes = relationship("Episode", back_populates="series")

    @validates("name")
    def validate_name(self, key, name):
        if len(name) < 2:
            raise ValueError("Name is too short!")
        return name

class Episode(Base):
    __tablename__ = "episode"

    number = Column("number", Integer, primary_key=True)
    name = Column("name", String)
    series_name = Column(String, ForeignKey("series.name"))
    series = relationship('Series', back_populates='episodes')

    @validates("number")
    def validate_year(self, key, number):
        if number > 1000:
            raise ValueError("Series cannot have more than 1000 episodes")
        return number
    
class Producer(Base):
    __tablename__ = "producer"

    id = Column("id", Integer, primary_key=True)
    name = Column("firstname", String)
    age = Column("age", Integer)    
    series_name = Column(String, ForeignKey("series.name"))
    series = relationship('Series', back_populates='producer')

    @validates("age")
    def validate_year(self, key, age):
        if not age.isnumeric:
            raise ValueError("Age must be a number!")
        return age