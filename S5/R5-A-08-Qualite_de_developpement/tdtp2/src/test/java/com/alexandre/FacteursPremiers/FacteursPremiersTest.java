package com.alexandre.FacteursPremiers;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class FacteursPremiersTest {
    @Test
    public void testGenerateWithOne() {
        assertEquals(List.of(), FacteursPremiers.generate(1));
    }

    @Test
    public void testGenerateWithTwo() {
        assertEquals(List.of(2), FacteursPremiers.generate(2));
    }

    @Test
    public void testGenerateWithSix() {
        assertEquals(List.of(2, 3), FacteursPremiers.generate(6));
    }

    @Test
    public void testGenerateWithEight() {
        assertEquals(List.of(2, 2, 2), FacteursPremiers.generate(8));
    }
}
