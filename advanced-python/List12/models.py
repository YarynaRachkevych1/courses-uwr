from sqlalchemy import Column, Integer, String, Date, ForeignKey
from sqlalchemy.orm import relationship, validates
from flask_sqlalchemy import SQLAlchemy
from datetime import date

db = SQLAlchemy()

class Producer(db.Model):
    __tablename__ = 'producer'

    id = Column(Integer, primary_key=True, autoincrement=True)
    name = Column(String, nullable=False)
    age = Column(Integer, nullable=False)
    series = relationship('Series', back_populates='producer')

    @validates('age')
    def validate_age(self, key, age):
        if not age.isnumeric:
            raise ValueError('Age must be a number!')
        return age

    def serialize(self):
        return {
            'id': self.id,
            'name': self.name,
            'age' : self.age
        }


class Series(db.Model):
    __tablename__ = 'series'

    id = Column(Integer, primary_key=True, autoincrement=True)
    title = Column(String, nullable=False)
    release_year = Column(Date, nullable=False)
    producer_id = Column(Integer, ForeignKey('producer.id'))
    producer = relationship('Producer', back_populates='series')
    episodes = relationship('Episode', back_populates='series')

    @validates('title')
    def validate_title(self, key, title):
        if len(title) < 1:
            raise ValueError("Title is too short!")
        return title

    def serialize(self):
        return {
            'id': self.id,
            'title': self.title,
            'release_year': date.isoformat(self.release_year),
            'producer_id': self.producer_id
        }


class Episode(db.Model):
    __tablename__ = 'episode'

    id = Column(Integer, primary_key=True, autoincrement=True)
    title = Column(String, nullable=False)
    duration = Column(Integer, nullable=False)
    series_id = Column(Integer, ForeignKey('series.id'))
    series = relationship('Series', back_populates='episodes')

    @validates('duration')
    def validate_duration(self, key, duration):
        if duration > 100:
            raise ValueError("An episode can't be longer than 100min")
        return duration

    def serialize(self):
        return {
            'id': self.id,
            'title': self.title,
            'duration': self.duration,
            'series_id': self.series_id
        }


models = {
    'producer': Producer,
    'series': Series,
    'episode': Episode,
}
