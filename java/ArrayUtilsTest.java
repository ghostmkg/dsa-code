package algorithms.utils;
import static org.junit.jupiter.api.Assertions.*;


public class ArrayUtilsTest {

    int[] sample = {1, 3, 5, 7, 9};

    @Test
    void testFindMax() {
        assertEquals(9, ArrayUtils.findMax(sample));
    }

    @Test
    void testFindMin() {
        assertEquals(1, ArrayUtils.findMin(sample));
    }

    @Test
    void testSum() {
        assertEquals(25, ArrayUtils.sum(sample));
    }

    @Test
    void testAverage() {
        assertEquals(5.0, ArrayUtils.average(sample));
    }

    @Test
    void testReverse() {
        int[] arr = {1, 2, 3, 4};
        ArrayUtils.reverse(arr);
        assertArrayEquals(new int[]{4, 3, 2, 1}, arr);
    }

    @Test
    void testContains() {
        assertTrue(ArrayUtils.contains(sample, 5));
        assertFalse(ArrayUtils.contains(sample, 10));
    }

    @Test
    void testEmptyArray() {
        int[] empty = {};
        assertThrows(IllegalArgumentException.class, () -> ArrayUtils.findMax(empty));
        assertThrows(IllegalArgumentException.class, () -> ArrayUtils.findMin(empty));
        assertThrows(IllegalArgumentException.class, () -> ArrayUtils.average(empty));
    }

    @Test
    void testNullArray() {
        int[] arr = null;
        assertEquals(0, ArrayUtils.sum(arr));
        assertFalse(ArrayUtils.contains(arr, 1));
    }
}
