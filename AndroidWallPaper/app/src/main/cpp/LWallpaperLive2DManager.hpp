/**
 * Copyright(c) Live2D Inc. All rights reserved.
 *
 * Use of this source code is governed by the Live2D Open Software license
 * that can be found at https://www.live2d.com/eula/live2d-open-software-license-agreement_en.html.
 */

#pragma once

#include <CubismFramework.hpp>
#include <Math/CubismMatrix44.hpp>
#include <Type/csmVector.hpp>
#include <string>

class LWallpaperModel;

/**
* @brief サンプルアプリケーションにおいてCubismModelを管理するクラス<br>
*         モデル生成と破棄、タップイベントの処理、モデル切り替えを行う。
*
*/
class LWallpaperLive2DManager
{

public:
    /**
    * @brief   クラスのインスタンス（シングルトン）を返す。<br>
    *           インスタンスが生成されていない場合は内部でインスタンを生成する。
    *
    * @return  クラスのインスタンス
    */
    static LWallpaperLive2DManager* GetInstance();

    /**
    * @brief   クラスのインスタンス（シングルトン）を解放する。
    *
    */
    static void ReleaseInstance();

    /**
    * @brief   現在のシーンで保持しているモデルを返す
    *
    * @return      モデルのインスタンスを返す。
    */
    LWallpaperModel* GetModel() const;

    /**
    * @brief   現在のシーンで保持しているすべてのモデルを解放する
    *
    */
    void ReleaseModel();

    /**
    * @brief   画面をドラッグしたときの処理
    *
    * @param[in]   x   画面のX座標
    * @param[in]   y   画面のY座標
    */
    void OnDrag(Csm::csmFloat32 x, Csm::csmFloat32 y);//const;

    /**
    * @brief   画面をタップしたときの処理
    *
    * @param[in]   x   画面のX座標
    * @param[in]   y   画面のY座標
    */
    void OnTap(Csm::csmFloat32 x, Csm::csmFloat32 y);

    /**
    * @brief   画面を更新するときの処理
    *          モデルの更新処理および描画処理を行う
    */
    void OnUpdate() const;

    /**
     * @brief 重力加速度の値の設定
     * @param[in]   gravity   重力加速度(-9.81~9.81)
     */
    void SetGravitationalAccelerationX(float gravity);

    void changeModel(std::string modelDirectoryName);//const;//灯篭が追加

private:
    /**
    * @brief  コンストラクタ
    */
    LWallpaperLive2DManager();

    /**
    * @brief  デストラクタ
    */
    virtual ~LWallpaperLive2DManager();

    /**
    * @brief ディレクトリパスの設定
    *
    * モデルのディレクトリパスを設定する
    */
    void SetAssetDirectory(std::string& path);
    //void SetAssetDirectory(const std::string& path);

    /**
    * @brief モデルの読み込み
    *
    * モデルデータの読み込み処理を行う
    *
    * @param[in] modelDirectory モデルのディレクトリ名
    */
    void LoadModel(std::string modelDirectoryName);
    //元の->
    //void LoadModel(const std::string modelDirectoryName);

    Csm::CubismMatrix44*        _viewMatrix; ///< モデル描画に用いるView行列
    LWallpaperModel*  _model; ///< モデルインスタンス

    /**
    *@brief モデルデータのディレクトリ名
    * このディレクトリ名と同名の.model3.jsonを読み込む
    */
    Csm::csmChar* _modelDirectoryName = "Hiyori";//MangaJKはモーションがないので、モーション再生はひよりでテスト
    //Csm::csmChar* _modelDirectoryName = "MangaJK02"; ///< 初期読み込みモデル
    //元のコード->
    //const Csm::csmChar* _modelDirectoryName = "Hiyori";
    std::string _currentModelDirectory; ///< 現在のモデルのディレクトリ
};
