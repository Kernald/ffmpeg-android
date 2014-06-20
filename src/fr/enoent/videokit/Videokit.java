package fr.enoent.videokit;

public final class Videokit {
	static {
		System.loadLibrary("videokit");
	}
	
	private static Videokit _instance = null;
	
	public static Videokit getInstance() {
		if (_instance == null) {
			_instance = new Videokit();
		}
		
		return _instance;
	}
	
	private Videokit() {}
	
	/**
	 * Call FFmpeg with specified arguments
	 * @param args FFmpeg arguments
	 * @return true if success, false otherwise
	 */
	public boolean process(String[] args) {
		String[] params = new String[args.length + 1];
		params[0] = "ffmpeg";
		System.arraycopy(args, 0, params, 1, args.length);
		
		return run(params);
	}
	
	private native boolean run(String[] args);
}
