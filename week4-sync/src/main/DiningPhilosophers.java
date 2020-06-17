/**
 * 
 */
package main;

/**
 * @author Admin
 *
 */
public class DiningPhilosophers {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {

		final Philosopher[] philosophers = new Philosopher[5];
		Object[] forks = new Object[philosophers.length];

		for (int i = 0; i < forks.length; i++) {
			forks[i] = new Object();
		}

		for (int i = 0; i < philosophers.length; i++) {
			Object leftFork = forks[i];
			Object rightFork = forks[(i + 1) % forks.length];

			if (i % 2 == 1) {
				// The odd index philosopher picks up the right fork first
				philosophers[i] = new Philosopher(rightFork, leftFork);
			} else {
				philosophers[i] = new Philosopher(leftFork, rightFork);
			}

			Thread t = new Thread(philosophers[i], "Philosopher " + (i + 1));
			t.start();
		}
	}

}
