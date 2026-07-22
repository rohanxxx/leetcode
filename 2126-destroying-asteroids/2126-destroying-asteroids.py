class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        asteroids.sort()

        curMass = mass
        for asteroid in asteroids:
            if curMass >= asteroid:
                curMass += asteroid
            else:
                return False
        return True
