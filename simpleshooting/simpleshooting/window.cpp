//ウィンドウ制御クラスの実装

#include"window.h"

namespace
{
	//-------------------------------
	/**
	* @brief ウィンドウプロシージャ
	* @param handle ウィンドウハンドル
	* @param msg メッセージ
	* @param wParam メッセージパラメータ
	* @param lParam メッセージパラメータ
	* @return 処理結果
	*/
	LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		}
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}

//-------------------------------
/**
	* @brief ウィンドウの作成
	* @param instance インスタンスハンドル
	* @param　width 横幅
	* @param height 縦幅
	* @param name ウィンドウ名
	* @return 生成の成否
	*/
[[nodiscard]] HRESULT create(HINSTANCE instance, int width, int height, std::string_view name)noexcept
{
	//ウィンドウの定義
	WNDCLASS wc{};
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = instance;
	wc.lpszClassName = name.data();
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);


}