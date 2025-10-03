import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

public class MathUtilsTest {

    @Test
    public void testGCD() {
        assertEquals(6, MathUtils.gcd(54, 24));
        assertEquals(1, MathUtils.gcd(17, 13));
        assertEquals(10, MathUtils.gcd(0, 10));
    }

    @Test
    public void testLCM() {
        assertEquals(216, MathUtils.lcm(54, 24));
        assertEquals(221, MathUtils.lcm(13, 17));
        assertEquals(0, MathUtils.lcm(0, 10));
    }

    @Test
    public void testIsPrime() {
        assertTrue(MathUtils.isPrime(7));
        assertFalse(MathUtils.isPrime(10));
        assertFalse(MathUtils.isPrime(1));
        assertTrue(MathUtils.isPrime(2));
        assertTrue(MathUtils.isPrime(13));
        assertFalse(MathUtils.isPrime(0));
    }
}
